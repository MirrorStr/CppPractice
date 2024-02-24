# 设置你的项目源代码和构建目录
$sourceDir = "D:\Project\C++"
$buildDir = "D:\Project\C++\build"

# 创建构建目录（如果不存在）
if (-not (Test-Path $buildDir)) {
    New-Item -ItemType Directory -Path $buildDir
}

# 切换到构建目录
Set-Location $buildDir

# 清空构建目录（删除所有文件和子目录，不提示确认）
Get-ChildItem -Recurse | Remove-Item -Recurse -Force

# 运行CMake配置（生成Makefile或Visual Studio项目文件）
& cmake -G "MinGW Makefiles" $sourceDir

#编译
& cmake --build $buildDir

# 切换回项目目录
Set-Location $sourceDir
