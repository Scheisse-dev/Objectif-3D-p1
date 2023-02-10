Param(
    [parameter()]
    [String]$path
)

function IsPublic
{
   param([string]$line, [boolean]$result)
   
   if ($line.Contains("public:"))
   {
       return $true
   }
   elseif ($line.Contains("private:") -or $line.Contains("protected:")) 
   {
       return $false 
   }
   return $result
}

function AddFlag
{
    param([string]$currentFlag, [string]$newFlag)
    if ($currentFlag.Contains($newFlag))
    {
        return $currentFlag
    }
    if  ([string]::IsNullOrEmpty($currentFlag))
    {
        return "BindingFlags::$newFlag"
    }
    return "$currentFlag | BindingFlags::$newFlag"
}

function ReplaceStr
{
    param([string]$str, [string[]]$toReplace, [string]$to)
    for ($i = 0; $i -lt $toReplace.Count; $i = $i +1)
    {
        $str = $str.Replace($toReplace[$i], $to)
    }
    return $str
}

Get-ChildItem $path -Recurse -Filter *.h | 
    Foreach-Object{
	$fullpath = $_.FullName
	$className = (Get-Item $fullpath).BaseName
	$includePath = $fullPath.Replace($path, "")
	$includePath = $includePath.Substring(0, $includePath.Length)
	$includePath = $includePath.Replace("\", "/")

    if ($className -eq "Object")
    {
        return
    }

    $isPublic = $false
    $isObject = $false
    $isStatic = $false
    $isConst = $false
    $class = ""
    $flags = ""

    $fileContent = (Get-Content $fullPath) -as [Collections.ArrayList]
    for ($i = 0; $i -lt $fileContent.Count; $i = $i + 1)
    {
        $line = $fileContent[$i]
        if ($line -match "UCLASS()")
        {
            $isObject = $true
            $class = $fileContent[$i+1]
            $class = $class.Substring(0, $class.IndexOf(':') -1)
            $class = $class.Substring($class.LastIndexOf(' ') + 1)
        }

        if ($isObject)
        {
            if ([string]::IsNullOrEmpty($line))
            {
                continue
            }

            $isPublic = IsPublic -line $line -result $isPublic

            if ($line -match "UFUNCTION()")
            {
                if ($line -match "static")
                {
                    $isConst = $true
                    #usefull ?
                }

                $const = $line.Substring($line.LastIndexOf(')') + 1)
                if ($const -match "const")
                {
                    $isStatic = $true
                }

                $flags = ""
                if ($isPublic)
                {
                    $flags = AddFlag -currentFlag $flags -newFlag "Public"
                }
                else
                {
                    $flags = AddFlag -currentFlag $flags -newFlag "NoPublic"
                }
                if ($isStatic)
                {
                    $flags = AddFlag -currentFlag $flags -newFlag "Static"
                }

                $name = $line.Substring(0, $line.LastIndexOf('('))
                $name = $name.Substring($name.LastIndexOf(' ') + 1)

                $params = $line.Substring(0, $line.LastIndexOf(')'))
                $params = $params.Substring($line.LastIndexOf('(') + 1)

                if ([string]::IsNullOrEmpty($params.Trim()))
                {
                    $params = "{}"
                }
                else
                {
                    $vector = $params -Split ','
                    $params = "(std::vector{"
                    for ($j = 0; $j -lt $vector.Count - 1; $j = $j + 1)
                    {
                        $pname = $vector[$j].TrimStart()
                        $pname = ReplaceStr -str $pname -toReplace @("const", "*", "&") -to ""
                        $pname = $pname.Substring($pname.LastIndexOf(' ') + 1).Trim()
                        $params += "new Engine::Reflection::ParameterInfo(`"$pname`", $j), "
                    }
                    $pname = $vector[$vector.Count - 1]
                    $pname = $pname.Substring($pname.LastIndexOf(' ') + 1)
                    $params += "new Engine::Reflection::ParameterInfo(`"$pname`", $j)})"
                }

                $res = "REGISTER_METHOD($name, &$class::$name, $params, $flags)"
        
                if ($fileContent[$i + 1] -match "REGISTER_METHOD")
                {
                    $fileContent.RemoveAt($i + 1)
                    $fileContent.Insert($i + 1, $res)
                }
                else
                {
                    $fileContent.Insert($i + 1, $res)
                }
            }
        }
    }

    for ($i = 0; $i -lt $fileContent.Count; $i = $i + 1)
    {
        $line = $fileContent[$i]
        if ($line -match "REGISTER_METHOD" -and $fileContent[$i - 1] -notmatch "UFUNCTION()")
        {
            $fileContent.RemoveAt($i)
        }
    }

    $fileContent | Out-File $includePath
}