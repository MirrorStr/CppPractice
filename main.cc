/**
 * @file main.cc
 * @author wanjuncong (Magcil7@outlook.com)
 * @brief 
 * @version 0.1
 * @date 2024-02-24
 * 
 * @copyright Copyright (c) WANJUNCONG 2024
 * 
 */

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

// #include "Head.hh"
#include "Api.hh"

using namespace std;


struct Test
{
    vector<int> vecNum;
};


/**
 * @brief 
 * 
 * @return int 
 */
int main()
{

    #if 1
    /*  */
    /* ┎─────────────────────────────────────────────────────────────────┒ */
    
    /* 结论： */
    /* ┗─────────────────────────────────────────────────────────────────┚ */
    #endif

    #if 1
    /* 测试int转换string */
    /* ┎─────────────────────────────────────────────────────────────────┒ */
    int iNum = 7;
    std::stringstream ssTemp;
    std::string strTemp;

    ssTemp << iNum;
    strTemp = std::to_string(iNum);
    std::cout << "Convert 'int' to string by 'stringsstream':" << ssTemp.str() << std::endl;
    std::cout << "Convert 'int' to string by 'to_string()': " << strTemp << std::endl;
    /* 结论：都可以啊，不i错不错 */

    /* ┗─────────────────────────────────────────────────────────────────┚ */
    #endif


    /* 测试声明和定义分离 */
    /* ┎─────────────────────────────────────────────────────────────────┒ */
    // FuncInHead();
    // UseHeadFunc();
    /* 结论： */
    /**
     *  定义在其他文件中是可以用的，我这边是通过子模块的函数间接使用一个声明在头文件但是定义在此的函数
     *  
     */
    /* ┗─────────────────────────────────────────────────────────────────┚ */

    /* 测试容器结构体是否会变化大小 */
    /* ┎─────────────────────────────────────────────────────────────────┒ */
    // Test stData, stMiniD, stLarge,stMax;
    // int iNum[5] = {1, 2, 3, 4, 5};
    // int iBigNum[6] = {1, 2, 3, 4, 5, 6};
    // int iMax[100] = {0};
    // stData.vecNum.assign(iNum, iNum+5);
    // stMiniD.vecNum.assign(iNum, iNum+2);
    // stLarge.vecNum.assign(iBigNum, iBigNum+6);
    // stMax.vecNum.assign(iMax, iMax+100);

    // cout << "stData size: " << sizeof(stData) 
    //      << "\nTest struct size: " << sizeof(Test) 
    //      << "\n stMiniD size: " << sizeof(stMiniD) 
    //      << "\n Test struct size(2cd times):" << sizeof(Test)
    //      << "\n stLarge size: " << sizeof(stLarge) 
    //      << "\n Test struct size(3rd times):" << sizeof(Test)
    //      << "\n stMax size: " << sizeof(stMax) 
    //      << "\n Test struct size(4th times):" << sizeof(Test) << endl; 

    /* 结论： */
    /* 无论成员怎么变化，结构体对象的大小都是固定的。因为其容器类似指针只是数据的地址实际上并不在这。 */
    /* ┗─────────────────────────────────────────────────────────────────┚ */

    /* 测试string转int */
    /* ┎─────────────────────────────────────────────────────────────────┒ */
    // std::string strHex = "37";
    // int iHex = stoi(strHex);

    // std::cout << iHex << std::endl;

    /* ┗─────────────────────────────────────────────────────────────────┚ */

    /*  */
    /* ┎─────────────────────────────────────────────────────────────────┒ */
    // std::cout << "Hello World" << std::endl;
    /* ┗─────────────────────────────────────────────────────────────────┚ */

    
    /* 测试打开文件 */
    /* ┎─────────────────────────────────────────────────────────────────┒ */
    // std::string filePath = R"(data\subdata\subsubdata\sub_log.txt)";
    // std::ifstream file(filePath);

    // if (file.is_open()) {
    //     std::string line;
    //     while (std::getline(file, line)) {
    //         std::cout << line << std::endl;
    //     }
    //     file.close();
    // } else {
    //     std::cout << "无法打开文件" << std::endl;
    // }
    /* ┗─────────────────────────────────────────────────────────────────┚ */

    /* 不知道什么 */
    /* ┎─────────────────────────────────────────────────────────────────┒ */
    // declaring three numbers
    // int a = 10;
    // int b = 2;
    // int c = 6;
  
    // // outermost if else
    // if (a < b) {
    //     // nested if else
    //     if (c < b) {
    //         printf("%d is the greatest", b);
    //     }
    //     else {
    //         printf("%d is the greatest", c);
    //     }
    // }
    // else {
    //     // nested if else
    //     if (c < a) {
    //         printf("%d is the greatest", a);
    //     }
    //     else {
    //         printf("%d is the greatest", c);
    //     }
    // }
    /* ┗─────────────────────────────────────────────────────────────────┚ */
  
    return 0;
}

void FuncInHead(void)
{
    std::cout << "This is a funcation declra in Head.hh but define in main.cc." << std::endl;
}