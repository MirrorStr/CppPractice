/**
 * @file WhiteBorad.hh
 * @author wanjuncong (Magcil7@outlook.com)
 * @brief
 * @version 0.1
 * @date 2024-09-22
 *
 * @copyright Copyright (c) WANJUNCONG 2024
 *
 */
#ifndef __WHITE_BORAD_H__
#define __WHITE_BORAD_H__

#include <iostream>
#include <string>

#if 1
/*  */
/* ┎─────────────────────────────────────────────────────────────────┒ */
#endif
template <typename T>
void DisplayMsg(std::string strMsg, T Data) {
    std::cout << strMsg << std::endl;
}

template <typename T> /* 重载模板，第一个参数改为char */
void DisplayMsg(char iNum, T Data) {
    std::cout << std::hex << iNum << std::endl;
}

template <typename T> /* 重载模板，只保留一个参数 */
void DisplayMsg(char iNum) {
    std::cout << std::hex << iNum << std::endl;
}

template <> /* 重载模板，只保留一个参数,，并特化 */
void DisplayMsg<char>(char iNum) {
    std::cout << std::hex << iNum << std::endl;
}
/* 结论： */
/* ┗─────────────────────────────────────────────────────────────────┚ */

#endif /* __WHITE_BORAD_H__ */