#include <windows.h>

#include "Api.hh"

void UseHeadFunc(void) {
    std::cout << "Try to use func in Head.hh" << std::endl;
    FuncInHead();
}

/**
 * @brief 尝试使用win api设置动态库，但是没用
 *
 */
void LoadSharedLib(void) {
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

void DoSomething(void) { std::cout << "DoSomething" << std::endl; }

#if 0   /* 测试实验代码，未完全验证，仅作备份 */
/*  */
/* ┎─────────────────────────────────────────────────────────────────┒ */
// void copy_to_clipboard(const std::string &text) {
//     if (OpenClipboard(NULL)) {
//         HGLOBAL hMem = GlobalAlloc(GMEM_ZEROINIT, text.size() + 1);
//         std::cout << "[Debug]:text.size:" << text.size() << std::endl;
//         if (hMem) {
//             LPSTR pMem = (LPSTR)GlobalLock(hMem);
//             memcpy(pMem, text.c_str(), text.size() + 1);
//             GlobalUnlock(hMem);

//             EmptyClipboard();
//             SetClipboardData(CF_TEXT, hMem);
//         }
//         CloseClipboard();
//     } else {
//         std::cerr << "Failed to open clipboard." << std::endl;
//     }
// }

// /* 剪贴板2 */
// void copy_to_clipboard(const std::string &text) {
//     const size_t text_length = text.length();
//     HGLOBAL hGlobalMemory =
//         GlobalAlloc(GMEM_MOVEABLE, (text_length + 1) * sizeof(TCHAR));
//     if (hGlobalMemory == NULL) {
//         return; // 内存分配失败
//     }

//     LPCTSTR lptstrBuffer = (LPCTSTR)GlobalLock(hGlobalMemory);
//     memcpy((void *)lptstrBuffer, text.c_str(),
//            (text_length + 1) * sizeof(TCHAR));
//     GlobalUnlock(hGlobalMemory);

//     if (!OpenClipboard(NULL)) {
//         GlobalFree(hGlobalMemory); // 打开剪贴板失败，释放内存
//         return;
//     }

//     EmptyClipboard();                         // 清空剪贴板
//     SetClipboardData(CF_TEXT, hGlobalMemory); // 设置剪贴板数据
//     CloseClipboard();                         // 关闭剪贴板

//     // 注意：以下代码行可能不是必要的，因为 hGlobalMemory 已经通过
//     // SetClipboardData 传递给了剪贴板 GlobalFree(hGlobalMemory); //
//     // 释放内存，剪贴板已经接管了这块内存
// }
/* 结论： */
/* ┗─────────────────────────────────────────────────────────────────┚ */
#endif

