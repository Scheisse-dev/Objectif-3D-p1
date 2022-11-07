param(
    [Parameter()]
    [String]$path
)

$assemblyPath = $path + "\Assembly.h"
$str = "#pragma once`n"
$str = "#include `"Domain/AppDomain.h`"`n"

Write-Output "test"
Write-Output $assemblyPath

Get-ChildItem $path -Recurse -Filter *.h | 
        Foreach-Object {
            $fullPath = $_.FullName
            $className = (Get-Item $fullPath).BaseName
            $includePath = $fullPath.Replace($path, "")
            $includePath = $includePath.Substring(0, $includePath.Length)
            $includePath = $includePath.REplace("\", "/")

            $isObject = $false
            foreach($line in Get-Content $fullPath)
            {
                if($line -match "UCLASS")
                {
                    $isObject = $true
                }
            }
            if($isObject)
            {
                $str += "#include `"$includePath`"`n"
                $str += "REGISTER_CLASS($className)`n"
            }
        }

$str | Out-File $assemblyPath