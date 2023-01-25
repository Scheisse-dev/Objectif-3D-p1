param(
	[Parameter()]
	[String]$path
)


$assemblyPath = $path + "Test\A.h"
#$str = "#pragma once`n"
#$str = "#include `"Engine\Object\Object.h`"`n"


# Write-OutPut "test"
# Write-OutPut $assemblyPath


Get-ChildItem $path -Recurse -Filter *.h | 
   Foreach-Object {
	    $fullPath = $_.FullName
		$className = (Get-Item $fullPath).BaseName
        Write-Output $className
        if ($className -eq "A")
        {
            $file = Get-Content $fullPath #-as [Collections.Array]
            $pointeur = "&" + (Get-Item $fullPath).BaseName
		    $includePath = $fullPath.Replace($path, "")
            $includePath = $includePath.Substring(0, $includePath.Length)
            $includePath = $includePath.REplace("\", "/")
	        $isObject = $false

            foreach($line in Get-Content $fullPath)
            {
                    if($line -match "UFUNCTION")
                    {
                        $str += "REGISTER_FONCTION($className, $pointeur)`n"
                        
                    }

            }
          
        }
   }
$str + $file | Out-File $assemblyPath
