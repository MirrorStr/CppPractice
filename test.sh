# Description: 
# Author: 万俊聪
# Date: 
# Version: v0.1
#!/bin/bash


pwd
echo ${BASH_SOURCE[0]}


# 关键代码
SCRIPT_DIR=$(cd -- "$(dirname -- "${BASH_SOURCE[0]}")" &>/dev/null && pwd -P)
sc_dir="$(dirname -- "${BASH_SOURCE[0]}")"

echo "脚本路径2: ${sc_dir}"
echo "脚本所在目录：${SCRIPT_DIR}"