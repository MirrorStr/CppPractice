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
#include <windows.h>
#include <fstream>

#include "json/json.h"

#include "Api.hh"

using namespace std;

/**
 * @brief 
 * 
 * @return int 
 */
int main()
{

    #if 1
    /* json文件读写 */
    /* ┎─────────────────────────────────────────────────────────────────┒ */
    /* 打开一个输出文件，没有会创建 */
    std::ofstream sOutFile;
    std::string strOutPath("D:/Project/C++/data/");
    try
    {
        sOutFile.open(strOutPath + "data.json");
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return -1;
    }
    /* 准备好json内容 */
    Json::Value jsRoot;
    jsRoot["Meb1"] = "Hello";
    jsRoot["Meb2"] = 7;
    jsRoot["Meb3"] = true;
    /* 写入然后关闭 */
    sOutFile << jsRoot << std::endl;
    sOutFile.close();

    /* +=+=+=+=+= 读取文件 +=+=+=+=+= */
    std::string strReadPath("D:/Project/C++/data/DataRead.json");
    std::ifstream sFileRead(strReadPath);
#if 1
    /* 使用C风格的报错 */
    if (!sFileRead) {   /* 打开是否成功 */
        std::cout << "Can't open " << strReadPath << ", Error:" << strerror(errno) << "."  << std::endl;
        return -1; 
    }
#endif
    Json::Reader jsReader;
    Json::Value jsReadRoot;
#if 0
    /* 不用异常处理来解析 */
    if (jsReader.parse(sFileRead, jsReadRoot)) {    /* 解析成json对象 */
    std::cout << "jsReadRoot:" << jsReadRoot << std::endl;
    } else {
        std::cout << "Parse error" << std::endl;
    }
#else
    try
    {
        if (jsReader.parse(sFileRead, jsReadRoot)) {    /* 解析成json对象 */
            std::cout << "jsReadRoot:" << jsReadRoot << std::endl;
        } else {
            throw Json::Exception("Failed to parse jsReadRoot!");
        }
    }
    catch(const Json::Exception &e)
    {
        std::cerr << "Catch a json::exp with mesg: " << e.what() << '\n';
    }
#endif
    

    /* 结论： 写入很简单，打开输出流之后当作标准输出一样直接'<<'就完事了，都不用转string。二，对于输入，利用reader对象从文件流中
       解析除json对象然后就是随便操作了。
    */
    /* ┗─────────────────────────────────────────────────────────────────┚ */
    #endif

    #if 0
    /* json member测试 */
    /* ┎─────────────────────────────────────────────────────────────────┒ */
    Json::Value jsRoot;
    jsRoot["Meb1"] = "Hello";
    jsRoot["Meb2"] = 7;
    jsRoot["Meb3"] = true;
    Json::Value jsSub;
    jsSub["Head"] = 1;
    jsSub["Foot"] = 2;
    Json::Value jsSubArr;
    for (int i = 0; i < 3; i++) {
        Json::Value jsEle;  /* 数组元素 */
        jsEle["Ele"] = i;
        jsSubArr.append(jsEle);
    }
    jsSub["Arr"] = jsSubArr;
    jsRoot["MultiMeb"] = jsSub;
    auto Mebs = jsRoot.getMemberNames();    /* Root对象的所有成员 */
    std::cout << "--------------" << std::endl;
    for (auto Meb : Mebs) {
        std::cout << "- " << Meb << std::endl;
    }

    Mebs = jsSub.getMemberNames();  /* 子对象的所有成员 */
    std::cout << "--------------" << std::endl;
    for (auto Meb : Mebs) {
        std::cout << "- " << Meb << std::endl;
    }

    // 数组不能使用
    // Mebs = jsSubArr.getMemberNames();
    // std::cout << "--------------" << std::endl;
    // for (auto Meb : Mebs) {
    //     std::cout << "- " << Meb << std::endl;
    // }

    std::cout << "Root:\n" << jsRoot.toStyledString() << std::endl;

    /* 查看对象的大小，而不是数组 */
    std::cout << "jsRoot size:" << jsRoot.size() << std::endl;

    /* 使用find() */
    std::string strFind = "Meb1";
    Json::Value jsFind = jsRoot.find(strFind.data(), strFind.data() + strFind.size());
    std::cout << "jsFind1:" << jsFind.toStyledString() << std::endl;

    std::string strFind2 = "MMBB";
    Json::Value jsFind2 = jsRoot.find(strFind2.data(), strFind2.data() + strFind2.size());
    std::cout << "jsFind2:" << jsFind2.toStyledString() << std::endl;

    auto itJson = jsRoot.begin();
    std::cout << "\nitJson:" << (*itJson).toStyledString() << std::endl;


    std::cout << "\n Print json arr" << std::endl;
    for (auto Meb : jsSubArr) {
        std::cout << "- [Meb Ele]: " << Meb["Ele"].asInt() << std::endl;
        std::cout << "- " << Meb << std::endl;
    }
    std::cout << "Root:" << jsRoot << std::endl;
    /* 结论： */
    /* ┗─────────────────────────────────────────────────────────────────┚ */
    #endif

    #if 0
    /* 测试Json库 */
    /* ┎─────────────────────────────────────────────────────────────────┒ */
    /**
     * @attention 目前使用静态库编译，如果不包含静态库可能编译不通过。 
     * 
     */
    Json::Value jsTest;
    jsTest["Meb1"] = "Hello Json!";
    std::cout << "jsTest:" << jsTest["Meb1"].asString() << std::endl;
    
    /* 结论： */
    /* ┗─────────────────────────────────────────────────────────────────┚ */
    #endif

    #if /* 1 */     0
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