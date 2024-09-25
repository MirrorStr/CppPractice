/**
 * @file BasicFunc.cc
 * @author wanjuncong (Magcil7@outlook.com)
 * @brief
 * @version 0.1
 * @date 2024-09-08
 *
 * @copyright Copyright (c) WANJUNCONG 2024
 *
 */

/* Include ****************************************************************** */
#include "BasicFunc.hh"

/* Define ******************************************************************* */

/* Variable Definitions ***************************************************** */

/* Namespace Usage ********************************************************** */

/* Class Definitions ******************************************************** */

/* Function Definitions ***************************************************** */
/**
 * @brief 只是为了用于测试子模块可用
 *
 */
void HelloBasicFunc(void) { std::cout << "HelloBasicFunc" << std::endl; }

void SwallowInput(std::function<void(const string &strInput)> Func) {
    string strInput;

    while (std::getline(std::cin, strInput)) {
        if ((strInput == "q") || (strInput == "Q")) {
            std::cout << "\nProgram exit!" << std::endl;
            return;
        }

        Func(strInput);
    }
}
/* End of file ************************************************************** */