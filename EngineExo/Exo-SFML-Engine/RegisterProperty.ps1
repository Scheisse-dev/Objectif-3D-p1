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
    $flags = ""

    $fileContent = (Get-Content $fullPath) -as [Collections.ArrayList]
    for ($i = 0; $i -lt $fileContent.Count; $i = $i + 1)
    {
        $line = $fileContent[$i]
        if ($line -match "UCLASS()")
        {
            $isObject = $true
        }

        if ($isObject)
        {
            if ([string]::IsNullOrEmpty($line))
            {
                continue
            }

            $isPublic = IsPublic -line $line -result $isPublic

            if ($line -match "UPROPERTY()")
            {
                $flags = ""
                if ($isPublic)
                {
                    $flags = AddFlag -currentFlag $flags -newFlag "Public"
                }
                else
                {
                    $flags = AddFlag -currentFlag $flags -newFlag "NoPublic"
                }

                if ($line.Contains("static"))
                {
                    $flags = AddFlag -currentFlag $flags -newFlag "Static"
                }


                $isPointer = $line.Contains("*")
                $field = ReplaceStr -str $line -toReplace @("inline", "const", "static", "constexpr", "UPROPERTY()") -to ""
                $field = $field.TrimStart()
                if ($field.Contains(">"))
                {
                    $str = $field.Substring($field.IndexOf(">"), $field.IndexOf("="))
                    $isPointer = $str.Contains("*")
                }
                $field = $field.Substring($field.IndexOf(' ') + 1)
                $field = $field.Substring(0, $field.IndexOf(' ')).Trim()

                $result = ""
                if ($isPointer)
                {
                    $result = "REGISTER_FIELD($field, $field, $flags)"
                }
                else
                {
                    $result = "REGISTER_FIELD($field, &$field, $flags)"
                }

                Write-Output $res
        
                if ($fileContent[$i + 1] -match "REGISTER_FIELD")
                {
                    $fileContent.RemoveAt($i + 1)
                    $fileContent.Insert($i + 1, $result)
                }
                else
                {
                    $fileContent.Insert($i + 1, $result)
                }
            }
        }
    }

    for ($i = 0; $i -lt $fileContent.Count; $i = $i + 1)
    {
        if ($line -match "REGISTER_FIELD" -and $fileContent[$i - 1] -notmatch "UPROPERTY()")
        {
            $fileContent.RemoveAt($i)
        }
    }

    $fileContent | Out-File $includePath
}