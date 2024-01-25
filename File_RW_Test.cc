#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::string filePath = R"(data\subdata\subsubdata\sub_log.txt)";
    std::ifstream file(filePath);

    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            std::cout << line << std::endl;
        }
        file.close();
    } else {
        std::cout << "无法打开文件" << std::endl;
    }

    return 0;
}
