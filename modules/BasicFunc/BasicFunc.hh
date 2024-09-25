/**
 * @file BasicFunc.hh
 * @author wanjuncong (Magcil7@outlook.com)
 * @brief
 * @version 0.1
 * @date 2024-09-08
 *
 * @copyright Copyright (c) WANJUNCONG 2024
 *
 */
/* Preventing Duplicate Inclusion ******************************************* */
#ifndef __BASIC_FUNC_H__
#define __BASIC_FUNC_H__

/* Include ****************************************************************** */
#include <functional>
#include <iostream>

/* Define ******************************************************************* */
using namespace std;

/* Class ******************************************************************** */

/* Function Declarations **************************************************** */
void HelloBasicFunc(void);

void SwallowInput(std::function<void(const string &strInput)> Func);

#endif /* BASIC_FUNC_H */
/* End of file ************************************************************** */