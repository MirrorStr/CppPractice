#include <windows.h>

#include "Api.hh"

void UseHeadFunc(void)
{
    std::cout << "Try to use func in Head.hh" << std::endl;
    FuncInHead();
}

/**
 * @brief 尝试使用win api设置动态库，但是没用
 * 
 */
void LoadSharedLib(void)
{
    // 指定DLL文件的完整路径
    LPCSTR dllPath = "D:\\Project\\C++\\lib\\dll";

    // 使用LoadLibraryEx函数加载DLL文件
    HMODULE hDll = LoadLibraryEx(dllPath, NULL, LOAD_WITH_ALTERED_SEARCH_PATH);
    
    std::cout << "Hear?" << std::endl;
    if (hDll != NULL) {
        // DLL加载成功，可以继续使用
        // Do something with the loaded DLL
        // 卸载DLL
        // FreeLibrary(hDll);
        std::cout << "Load shared lib successfully." << std::endl;
    } else {
        // DLL加载失败
        // Handle error
        std::cout << "Failed to load shared lib!" << std::endl;
    }
}