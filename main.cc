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

#include <algorithm>
// #include <comdef.h> /* wcout需要用到的头文件 */
#include <fstream>
#include <functional>
#include <iostream>
#include <iterator>
#include <locale.h>
#include <sstream>
#include <string>
#include <thread>
#include <vector>
// #include <windows.h> # 通过宏定义控制包含
#include <fmt/core.h>                        /* fmt格式化库 */
#include <json/json.h>                       /* CPP json库头文件 */
#include <spdlog/sinks/basic_file_sink.h>    // 文件日志支持
#include <spdlog/sinks/stdout_color_sinks.h> // 控制台彩色日志支持
#include <spdlog/spdlog.h>

#include "BasicFunc.hh"
#include "WhiteBorad.hh" /* 测试，验证功能用的模块 */

#if 0
/* 效果一般，不好用 */
/* ┎─────────────────────────────────────────────────────────────────┒ */
// 自定义宏，添加文件名、行号和函数名
#define LOG_INFO(...)                                               \
    spdlog::info("[{}:{}:{}] {}", __FILE__, __LINE__, __FUNCTION__, \
                 fmt::format(__VA_ARGS__))
#define LOG_WARN(...)                                               \
    spdlog::warn("[{}:{}:{}] {}", __FILE__, __LINE__, __FUNCTION__, \
                 fmt::format(__VA_ARGS__))
#define LOG_ERROR(...)                                               \
    spdlog::error("[{}:{}:{}] {}", __FILE__, __LINE__, __FUNCTION__, \
                  fmt::format(__VA_ARGS__))
/* 结论： */
/* ┗─────────────────────────────────────────────────────────────────┚ */
#endif

using namespace std;

int main(int argc, char const *argv[])
{

#if 1
    /* 测试加上宏的日志库打印 */
    /* ┎─────────────────────────────────────────────────────────────────┒ */

    // 创建一个日志器
    auto console = spdlog::stdout_color_mt("console");

    // 设置日志格式
    console->set_pattern("[%Y-%m-%d %H:%M:%S.%e] [%^%L%$] [%s:%#] %v");

    // 记录一些日志
    console->info("This is an info message");
    console->warn("This is a warning message");
    console->error("This is an error message");
/* 结论：格式化都挺好的
但是打印文件和行号估计必须得用宏了。不过用basic_logger_mt替换项目中的mod几要好很多
对于一般的日志就放到模块专属文件中。重要的日志放到终端中打印*/
/* ┗─────────────────────────────────────────────────────────────────┚ */
#endif

#if 0
/* spdlog测试验证 */
/* ┎─────────────────────────────────────────────────────────────────┒ */
    // 输出到控制台
    spdlog::info("Hello, spdlog!(To console)");

    // 格式化日志
    spdlog::warn("This is a warning with number: {}", 42);

    // 输出到文件
    std::string strLogFile = "logs/logfile.txt";
    auto file_logger = spdlog::basic_logger_mt("file_logger", strLogFile);
    file_logger->info("This is a log message written to a file.File:{}", strLogFile);

    // 设置全局日志级别
    spdlog::set_level(spdlog::level::debug); // 设置为 debug 级别
    spdlog::debug("This is a debug message.");


    /* 超级循环测试日志打印 */
    for(int i = 0; i < 100000; i++) {
        spdlog::info("This is a info message. i:{}", i);
    }

/* 结论： */
/* ┗─────────────────────────────────────────────────────────────────┚ */
#endif

#if 0
/* json库测试 */
/* ┎─────────────────────────────────────────────────────────────────┒ */
    Json::Value jsHello;
    jsHello["Meb1"] = "Hello";
    jsHello["Meb2"] = 7;
    jsHello["Meb3"] = true;
    std::cout << "Print by cout:" <<jsHello << std::endl;
    fmt::print("jsHello: {}\n", jsHello.toStyledString());
    /* 结论： */
/* ┗─────────────────────────────────────────────────────────────────┚ */
#endif

#if 0
/* fmt库引入和vcpkg测试 */
/* ┎─────────────────────────────────────────────────────────────────┒ */
    fmt::print("Hello World! From fmt\n");
/* 结论： */
/* ┗─────────────────────────────────────────────────────────────────┚ */
#endif

#if 0
    /* 验证循环输入函数 */
    /* ┎─────────────────────────────────────────────────────────────────┒ */

    auto Temp = [](const string &strInput) {
        std::cout << strInput << std::endl;
    };

    SwallowInput(Temp); /* 会一直循环输入，然后通过传入的函数对输入进行处理 */

/* 结论： */
/* ┗─────────────────────────────────────────────────────────────────┚ */
#endif

#if 0
    auto readWideInput = [](void) -> std::wstring {
        std::vector<wchar_t> buffer;
        wchar_t              c;
        while (std::wcin.get(c)) {
            if (c == L'q' || c == L'Q') {
                break;
            }
            buffer.push_back(c);
        }
        return std::wstring(buffer.begin(), buffer.end());
    };

    // 设置控制台输出编码为 UTF-8
    SetConsoleOutputCP(CP_UTF8);
    // 设置控制台输入编码为 UTF-8
    SetConsoleCP(CP_UTF8);

    std::wstring strInput;

    std::wcout << L"请输入文本（输入完成后按q或Q结束输入）：" << std::endl;
    std::cout << "test" << std::endl;
    strInput = readWideInput();

    // 移除所有的换行符和回车符
    strInput.erase(std::remove(strInput.begin(), strInput.end(), L'\n'),
                   strInput.end());
    strInput.erase(std::remove(strInput.begin(), strInput.end(), L'\r'),
                   strInput.end());

    std::wcout << L"\n处理后的文本：\n" << strInput << std::endl;

    // 复制到剪贴板
    if (OpenClipboard(NULL)) {
        EmptyClipboard();
        size_t  size = (strInput.length() + 1) * sizeof(wchar_t);
        HGLOBAL hMem = GlobalAlloc(GMEM_MOVEABLE, size);
        if (hMem != NULL) {
            wchar_t *pMem = (wchar_t *)GlobalLock(hMem);
            if (pMem != NULL) {
                memcpy(pMem, strInput.c_str(), size);
                GlobalUnlock(hMem);
                SetClipboardData(CF_UNICODETEXT, hMem);
            }
        }
        CloseClipboard();
        std::wcout << L"\n文本已复制到剪贴板。" << std::endl;
    } else {
        std::wcout << L"\n复制到剪贴板失败。" << std::endl;
    }

#endif

#if 0
/* 文本去除换行符功能 */
    /* ┎─────────────────────────────────────────────────────────────────┒ */
    // 设置控制台输出编码为 UTF-8
    SetConsoleOutputCP(CP_UTF8);
    // 设置控制台输入编码为 UTF-8
    SetConsoleCP(CP_UTF8);
    std::string line;
    std::string strInput;

    std::cout << "请输入文本（输入完成后按Ctrl+Z然后回车结束输入）：" << std::endl;

    // 读取多行输入，直到EOF (Ctrl+Z)
    while (std::getline(std::cin, line)) {
        if (line == "q" || line == "Q") {
            break;
        }
        strInput += line;
    }

    // 移除所有的换行符和回车符
    strInput.erase(std::remove(strInput.begin(), strInput.end(), '\n'), strInput.end());
    strInput.erase(std::remove(strInput.begin(), strInput.end(), '\r'), strInput.end());

    std::cout << "\n处理后的文本：\n" << strInput << std::endl;

    // 复制到剪贴板
    if (OpenClipboard(NULL)) {
        EmptyClipboard();
        HGLOBAL hMem = GlobalAlloc(GMEM_MOVEABLE, strInput.size() + 1);
        if (hMem != NULL) {
            char* pMem = (char*)GlobalLock(hMem);
            if (pMem != NULL) {
                memcpy(pMem, strInput.c_str(), strInput.size() + 1);
                GlobalUnlock(hMem);
                SetClipboardData(CF_TEXT, hMem);
            }
        }
        CloseClipboard();
        std::cout << "\n文本已复制到剪贴板。" << std::endl;
    } else {
        std::cout << "\n复制到剪贴板失败。" << std::endl;
    }
    /* ┗─────────────────────────────────────────────────────────────────┚ */
#endif

#if 0
    /* io stream迭代器使用 */
    /* ┎─────────────────────────────────────────────────────────────────┒ */
    istream_iterator<string> is(cin);
    istream_iterator<string> eof;
    vector<string>           text;
    copy(is, eof, back_inserter(text));
    sort(text.begin(), text.end());
    ostream_iterator<string> os(cout, " ");
    copy(text.begin(), text.end(), os);
/* 结论： */
/* ┗─────────────────────────────────────────────────────────────────┚ */
#endif

#if 0
    /* 模板重载测试 */
    /* ┎─────────────────────────────────────────────────────────────────┒ */
    string strT1("hello");
    char   iT2 = 0xFF;

    int iNUm = 3;

    DisplayMsg<int>(strT1, iNUm);
    DisplayMsg<int>(iT2, iNUm);
    DisplayMsg<long>(iT2);

    DisplayMsg<char>(iT2);

    char      i                       = 's';
    int       ddwadawdawdawdawdawdawd = 1;
    long long dwad                    = 123;

/* 结论：可以更换参数，可以特化模板，可以两种机制同时使用。 */
/* ┗─────────────────────────────────────────────────────────────────┚ */
#endif

#if 0
    /* 基础模块测试 */
    /* ┎─────────────────────────────────────────────────────────────────┒ */
    HelloBasicFunc();
    /* 结论： */
    /* ┗─────────────────────────────────────────────────────────────────┚ */
#endif

#if 0
    /* 定时器类测试 */
    /* ┎─────────────────────────────────────────────────────────────────┒ */
    Timer t(5000, DoSomething);
    t.start(); // 开始倒计时

    for (int i = 0; i < 10; i++) {
        std::cout << "模拟其他线程做点事。次数：" << i << std::endl;
    }

    // 主线程可以继续执行其他任务
    std::this_thread::sleep_for(std::chrono::seconds(10)); // 模拟主线程延迟

    t.stop(); // 停止定时器
    std::cout << "Timer done!" << std::endl;
/* 结论： */
/* ┗─────────────────────────────────────────────────────────────────┚ */
#endif

#if 0
/* 光标移动测试 */
/* ┎─────────────────────────────────────────────────────────────────┒ */
int dawd
int awdawdwa
int aw
int adwdawdawdwadwa
/* 结论： */
/* ┗─────────────────────────────────────────────────────────────────┚ */
#endif

#if 0
    /* 三目运算符测试 */
    /* ┎─────────────────────────────────────────────────────────────────┒ */
    int a = 1, b = 2, c = 3, d = 4, e = 5;

    auto k = a > b ? c : d > e ? d : e;

    std::cout << k << std::endl;
    // d:\Project\C++\CMakeLists.txt

/* 结论： */
/* ┗─────────────────────────────────────────────────────────────────┚ */
#endif

#if 0
    /* json解析优化测试 */
    /* ┎─────────────────────────────────────────────────────────────────┒ */
    Json::Value jsRoot;
    try {
        int iNum = jsRoot["Meb1"].asInt();
        bool bCheck = jsRoot["Meb2"].asBool();
        std::cout << "iNum:" << iNum << "\tbCheck:" << bCheck << std::endl;
    } catch (const std::exception &e) {
        std::cerr << e.what() << '\n';
    }

/* 结论： */
/* ┗─────────────────────────────────────────────────────────────────┚ */
#endif

#if 0
    /* 中文字符二进制查看 */
    /* ┎─────────────────────────────────────────────────────────────────┒ */

    std::string strIntput;

    do {
        std::getline(std::cin, strIntput);
        if (("q" == strIntput) || ("Q" == strIntput)) {
            std::cout << "Exit!" << std::endl;
            break;
        }
        std::cout << "========================" << std::endl;
        for (int i = 0; i < strIntput.length(); ++i) {
            std::cout << "[" << i + 1 << "]" << strIntput[i] << "\t"
                      << static_cast<int>(strIntput[i]) << std::endl;
        }
        std::cout << "========================" << std::endl;
    } while (true);

/* 结论： */
/* ┗─────────────────────────────────────────────────────────────────┚ */
#endif

#if 0
    /* 测试将长内容中文写道文件中去。 */
    /* ┎─────────────────────────────────────────────────────────────────┒ */
    std::ofstream outFile("D:\\Project\\C++\\data\\outfile.txt");
    if (!outFile.is_open()) {
        std::cout << "Can't open 'outfile.txt'!" << std::endl;
        return -1;
    }

    /* 手动写长内容string */
    // std::string strLongContent =
    //     "发展思维科学的又一个效果是使我们懂得如何更充分地发挥人脑的能力。比如人"
    //     "脑有创造的能力，这不是逻辑推理而是思想的飞跃，是所谓“灵感”。当然灵感也"
    //     "是从实践经验的总结提高得来的，要不是从实践当中来，小孩子刚一生下来不就"
    //     "能灵感一番，就能创造了吗？没有这样的事。而且创造的能力、灵感，是无法说"
    //     "清楚和无法教学生的。";

    /* 命令行获取内容 */
    std::string strLongContent;
    std::string line;
    while (std::getline(std::cin, line)) {
        if ("q" == line) {
            break;
        }
        strLongContent += line;
    }

    outFile << strLongContent << std::endl;
    outFile.close();
    std::cout << "Done!" << std::endl;
/* 结论： 命令行输入还是不行啊，乱码*/
/* ┗─────────────────────────────────────────────────────────────────┚ */
#endif

#if 0
    /* 使用中文 */
    /* ┎─────────────────────────────────────────────────────────────────┒ */

    string str = "string:C++技术网www.cjjjs.com";
    cout << str.c_str() << endl;

    wstring wstr = L"wstring:C++技术网www.cjjjs.com";
    setlocale(LC_ALL, "chs"); // 设置wcout输出中文
    wcout << wstr.c_str() << endl;
/* 结论： */
/* ┗─────────────────────────────────────────────────────────────────┚ */
#endif

#if 0
    /* 测试输出宽字符 */
    /* ┎─────────────────────────────────────────────────────────────────┒ */

    std::wstring wstrTemp = L"打完后丢啊我不hi都";
    setlocale(LC_ALL, "zh_CN.UTF-8"); // 设置wcout输出中文
    std::wcout << wstrTemp << std::endl;
    std::cout << "dawdadwdawd" << std::endl;
/* 结论： */
/* ┗─────────────────────────────────────────────────────────────────┚ */
#endif

#if 0
    /* 复制到剪贴板测试 */
    /* ┎─────────────────────────────────────────────────────────────────┒ */
    // 将要复制到剪贴板的字符串
    /* 手动给一长串内容，验证不会截断 */
    //     std::string textToCopy =
    //         "As the amount of information we have access to grows, such
    //         experiences\
// are becoming more and more common. We're flooded with more advice than\
// ever promising to make us smarter, healthier, and happier. We consume
    // more\
// books, podcasts, articles, and videos than we could possibly absorb. What
    // do\
// we really have to show for all the knowledge we've gained? How many of\
// the great ideas we've had or encountered have faded from our minds
    // before\ we even had a chance to put them into practice?";

    /* 按q退出 */
    // std::string line;
    // std::string strTemp;
    // while (std::getline(std::cin, line)) {
    //     if ("q" == line) {
    //         break;
    //     }
    //     strTemp += line;
    // }
    // std::cout << "strTemp:" << strTemp << std::endl;
    // // std::wstring textToCopy(strTemp.begin(), strTemp.end());
    // std::wstring textToCopy = L(strTemp);

    // std::cout << "textToCopy size:" << textToCopy.size() << std::endl;
    // std::wcout << "textToCopy:" << textToCopy << std::endl;

    // std::wstring textToCopy = L"你好！"; /* 较短内容 */
    std::wstring textToCopy =
        L"的同志要把这两类各门系统工程的共同基础连同其他数学工具通称为“系\
统工程学”，我认为这样做不一定妥当，名词和内容不相符。因为系统工程的理论\
基础，除了共同性的基础之外，每门系统工程又有其各自的专业基础。这是因为\
对象不同，当然要掌握不同对象本身的规律：例如工程系统工程要靠工程设计，军\
事系统工程要靠军事科学等。这里用表把各门系统工程和与之对应的特有学科\
基础列出来。"; /* 较长内容 */

    std::wcout << "textToCopy:" << textToCopy << std::endl;
    /* 打开剪贴板 */
    // if (OpenClipboard(NULL)) {
    //     // 清空剪贴板之前的内容
    //     EmptyClipboard();

    //     // 获取字符串的长度
    //     size_t len = (textToCopy.length() + 1) *
    //                  sizeof(wchar_t); // 计算Unicode字符串的长度

    //     // 分配内存并复制内容到内存中
    //     HGLOBAL hMem = GlobalAlloc(GMEM_MOVEABLE, len);
    //     if (hMem != NULL) {
    //         wchar_t *pMem = (wchar_t *)GlobalLock(hMem);
    //         if (pMem != NULL) {
    //             // 将宽字符字符串复制到内存中
    //             memcpy(pMem, textToCopy.c_str(), len);
    //             GlobalUnlock(hMem);

    //             // 将内存中的内容放入剪贴板
    //             SetClipboardData(CF_UNICODETEXT,
    //                              hMem); /* CF_UNICODETEXT 使用unicode字符 */
    //         }
    //     }

    //     // 关闭剪贴板
    //     CloseClipboard();
    // }
/* 结论： */
/* ┗─────────────────────────────────────────────────────────────────┚ */
#endif

#if 0
    /* 测试回车换行 */
    /* ┎─────────────────────────────────────────────────────────────────┒ */
    char HuiChe = '\r';    /* 回车 */
    char HuangHang = '\n'; /* 换行 */

    std::cout << "回车:" << (int)HuiChe << "\t换行:" << (int)HuangHang
              << std::endl;
/* 结论： */
/* ┗─────────────────────────────────────────────────────────────────┚ */
#endif

#if 0
    /* 回车删除工具测试 */
    /* ┎─────────────────────────────────────────────────────────────────┒ */

    std::string line;
    std::string strInput;

    // 读取多行输入，直到 EOF
    while (std::getline(std::cin, line)) {
        if ("q" == line) {
            break;
        }
        strInput += line;
    }
#if 0
    /* ASCCII打印 */
    std::cout << "\n==================\n" << std::endl;
    for (auto Chara : strInput) {
        std::cout << "Chara: " << Chara
                  << "\tASCII: " << static_cast<int>(Chara) << std::endl;
    }
    std::cout << "\n==================\n" << std::endl;
#endif

    std::cout << "\n==================\n" << std::endl;
    std::cout << "[strInput]:\n" << strInput << std::endl;

    /* 复制到剪贴板 */
    copy_to_clipboard(strInput);
    std::cout << "\n==================\n" << std::endl;
    std::cout << "The text has been copied to the clipboard." << std::endl;

    // 删除回车和换行符
    // input.erase(std::remove(input.begin(), input.end(), '\r'), input.end());
    // input.erase(std::remove(input.begin(), input.end(), '\n'), input.end());

    // string strInput;
    // while (true) {
    //     std::cout << "Enter a paragraph to start (press Q to exit)"
    //               << std::endl;
    //     std::getline(std::cin, strInput);
    //     if (("q" == strInput) || ("Q" == strInput)) {
    //         std::cout << "\nQuit program." << std::endl;
    //         std::cout << "===========================" << std::endl;
    //         break;
    //     }

    //     for (auto Chara : strInput) {
    //         std::cout << "Chara: " << Chara
    //                   << "\tASCII: " << static_cast<int>(Chara) << std::endl;
    //     }
    // }

/* 结论： */
/* ┗─────────────────────────────────────────────────────────────────┚ */
#endif

#if 0
    /* clang-format测试 */
    /* ┎─────────────────────────────────────────────────────────────────┒ */
    int a = 1;
    string strb = "ad";
    bool b = true;
    if (1) {
        std::cout << "sssss" << std::endl;
    }

/* 结论： */
/* ┗─────────────────────────────────────────────────────────────────┚ */
#endif

#if 0
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

#if /* 1 */ 0
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
    /* ┎─────────────────────────────────────────────────────────────────┒
     */
    // FuncInHead();
    // UseHeadFunc();
    /* 结论： */
    /**
     *  定义在其他文件中是可以用的，我这边是通过子模块的函数间接使用一个声明在头文件但是定义在此的函数
     *
     */
    /* ┗─────────────────────────────────────────────────────────────────┚
     */

    /* 测试容器结构体是否会变化大小 */
    /* ┎─────────────────────────────────────────────────────────────────┒
     */
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
    /* 无论成员怎么变化，结构体对象的大小都是固定的。因为其容器类似指针只是数据的地址实际上并不在这。
     */
    /* ┗─────────────────────────────────────────────────────────────────┚
     */

    /* 测试string转int */
    /* ┎─────────────────────────────────────────────────────────────────┒
     */
    // std::string strHex = "37";
    // int iHex = stoi(strHex);

    // std::cout << iHex << std::endl;

    /* ┗─────────────────────────────────────────────────────────────────┚
     */

    /*  */
    /* ┎─────────────────────────────────────────────────────────────────┒
     */
    // std::cout << "Hello World" << std::endl;
    /* ┗─────────────────────────────────────────────────────────────────┚
     */

    /* 测试打开文件 */
    /* ┎─────────────────────────────────────────────────────────────────┒
     */
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
    /* ┗─────────────────────────────────────────────────────────────────┚
     */

    /* 不知道什么 */
    /* ┎─────────────────────────────────────────────────────────────────┒
     */
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
    /* ┗─────────────────────────────────────────────────────────────────┚
     */

    return 0;
}

void FuncInHead(void)
{
    std::cout << "This is a funcation declra in Head.hh but define in main.cc."
              << std::endl;
}