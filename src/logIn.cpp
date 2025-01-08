#include "logIn.h"
#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
#include <sstream>

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
    std::string s;
    int flag = 0;
    while(std::getline(ifs,s))//直接读整行，不要按逗号一块一块读了
    {
        std::stringstream ss;//设为局部变量，每次循环流都会被清空
        std::string tmp_name;
        ss << s;
        std::getline(ss, tmp_name, ',');
        if(name.compare(tmp_name)==0)
        {
            flag = 1;
            std::cout << "请输入密码" << std::endl;
            std::cin >> password;
            std::string tmp_password;
            std::getline(ss, tmp_password, ',');
            if(password.compare(tmp_password)==0)
            {

            }

            break;
        }
        else
        {
            continue;
        }
    }
    if(flag==0)
    {
        std::cout << "账户不存在，请注册新账户" << std::endl;
    }
}

void logIn::incorporate()
{
    // 屁事没干的一天啊啊啊啊
}
