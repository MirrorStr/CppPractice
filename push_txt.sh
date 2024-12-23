# Descripttion:
# Author:万俊聪
#!/bin/bash

#Colors define.
###############################################################################
COLOR_RED="\x1b[31m"
COLOR_GREEN="\x1b[38;5;82m"
COLOR_YELLOW="\x1b[33m"
COLOR_PURPLE="\x1b[48;5;93m"

COLOR_GREEN_BACK="\x1b[48;5;28m"
COLOR_RED_BACK="\x1b[41m"
COLOR_YELLOW_BACK="\x1b[43m"

COLOR_RESET="\x1b[0m"
COLOR_HIGHLIGHT="\x1b[1m"

# 开始
###############################################################################
# 变量定义
FileName=""
Head="[${FileName}]: "
PorjectName=""

# 脚本主体
echo -e ${COLOR_PURPLE} ${COLOR_HIGHLIGHT}"+=+=+=+=+ ${PorjectName} ${Head} running... +=+=+=+=+"${COLOR_RESET}
echo -e "----------------------------------------\n"

git add *

git commit -m  "transfer txt $(date)"

git push msger

echo -e "\n----------------------------------------"
echo -e ${COLOR_GREEN_BACK} ${COLOR_HIGHLIGHT}"+=+=+=+=+ ${PorjectName} ${Head} has finished running. +=+=+=+=+"${COLOR_RESET}
# 文件结束
###############################################################################