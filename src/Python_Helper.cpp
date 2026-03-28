// ^_～ Initialized
// All-Kill Automaton   Debug++
// [RUN] BUILD MAP SPAWN PLAYER...

#include "Python_Helper.h"

#include "Settings.h"
#include <iostream>
#include <Python.h>
#include <fstream>
#include <sstream>
#include <string>

int Python_Helper(int size) {
#ifdef _WIN32
    system("chcp 65001 > nul"); // 运行时切换控制台代码页为 UTF-8
#endif
    int myCppVariable = size;

    // 设置环境变量（Python 端通过 os.getenv 读取）
    // Windows 下使用 _putenv_s，Linux/Mac 下使用 setenv
#ifdef _WIN32
    _putenv_s("CPP_DATA_VALUE", std::to_string(myCppVariable).c_str());
#else
    setenv("CPP_DATA_VALUE", std::to_string(myCppVariable).c_str(), 1);
#endif

    // --- 2. 初始化 Python ---
    Py_Initialize();

    // --- 3. 读取 Python 脚本文件内容 ---
    std::string scriptPath = "Image/image_batch2.py";
    std::ifstream file(scriptPath);

    if (!file.is_open()) {
        std::cerr << "错误：无法打开 Python 脚本文件！路径：" << scriptPath << std::endl;
        Py_Finalize();
        return 1;
    }

    // 将文件内容读入字符串流
    std::stringstream buffer;
    buffer << file.rdbuf();
    std::string pyCode = buffer.str();
    file.close();

    // --- 4. 直接执行 Python 代码字符串 ---
    int result = PyRun_SimpleString(pyCode.c_str());

    if (result != 0) {
        std::cerr << "Python 代码执行失败！请检查脚本语法。" << std::endl;

        // 打印 Python 错误
        if (PyErr_Occurred()) {
            PyErr_Print();
        }
        return 2;
    } else {
        std::cout << "Python 脚本执行成功！" << std::endl;
    }

    // --- 5. 清理 ---
    Py_Finalize();
    return 0;
}
