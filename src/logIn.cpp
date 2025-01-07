#include "logIn.h"
#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>

logIn::logIn()
{
    std::cout << "*******************************" << std::endl;
    std::cout << "*************1.登录************" << std::endl;
    std::cout << "*************2.注册************" << std::endl;
    std::cout << "*******************************" << std::endl;
}

void logIn::singIn()
{
    std::cout << "请输入账号" << std::endl;
    std::cin >> name;
    std::ifstream ifs;
    ifs.open("../test/Users.csv", std::ios::in); // ios不是命名空间，而是一个模板类
    if (!ifs.is_open())
    {
        std::cout << "open file failed" << std::endl;
    }
}

void logIn::incorporate()
{
    // 屁事没干的一天啊啊啊啊
}
