# Description: 编译整个项目的脚本
# Author: 万俊聪
# Date: 2025年2月27日
# Version: v0.1
#!/bin/bash

start_time=$(date +%s.%N)
SourceDir=$(cd -- "$(dirname -- "${BASH_SOURCE[0]}")" &>/dev/null && pwd -P) # 替换成脚本自身所在目录
BuildDir=${SourceDir}/build

echo "${SourceDir}, ${BuildDir}"

if [ ! -d ${BuildDir} ];then
mkdir ${BuildDir}
fi

# 清空文件
rm -rf ${BuildDir}/*
# 设置vcpkg
cmake --preset=default
# 编译
cmake --build ${BuildDir}

#输出时间
end_time=$(date +%s.%N)
elapsed_time=$(echo "$end_time - $start_time" | bc)
# 格式化输出（保留3位小数）
printf "脚本耗时: %.3f 秒\n" $elapsed_time