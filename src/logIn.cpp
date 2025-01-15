#include "logIn.h"
#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
#include <sstream>

int logIn::logInMenu()
{
    int option;
    std::cout << "*******************************" << std::endl;
    std::cout << "*************1.登录************" << std::endl;
    std::cout << "*************2.注册************" << std::endl;
    std::cout << "*************0.退出************" << std::endl;
    std::cout << "*******************************" << std::endl;
    std::cin >> option;
    return option;
}

int logIn::singIn()//返回1，程序运行出错，返回0，程序运行正常
{
    std::cout << "请输入账号" << std::endl;
    std::cin >> name;
    std::ifstream ifs;
    ifs.open("../test/Users.csv", std::ios::in); // ios不是命名空间，而是一个模板类
    if (!ifs.is_open())
    {
        std::cout << "open file failed" << std::endl;
        return 1;
    }
    std::string s;
    int flag = 0;
    while (std::getline(ifs, s)) // 直接读整行，不要按逗号一块一块读了
    {
        std::stringstream ss; // 设为局部变量，每次循环流都会被清空
        std::string tmp_name; // 或者放在外部声明，但记得每次循环结束要清空
        ss << s;
        std::getline(ss, tmp_name, ',');
        if (name.compare(tmp_name) == 0)
        {
            flag = 1;
            std::cout << "请输入密码" << std::endl;
            std::string tmp_password;
            char c;
            std::getline(ss, tmp_password, ',');
            while (1)
            {
                while ((c = _getch()) != '\r')
                {
                    password += c;
                    std::cout << '*';
                }
                std::cout << std::endl;
                if (password.compare(tmp_password) == 0)
                {
                    std::cout << "登录成功" << std::endl;
                    break;
                }
                else
                {
                    std::cout << "密码错误，请重新输入" << std::endl; // TODO:exit
                    password.clear();
                } // 重新输入时之前的输入要清空
            }

            break;
        }
        else
        {
            continue;//continue 是直接回到以一个大括号而不是调到最后一个花括号，但是仍会清空局部变量的值，break是直接跳出，不会经过大括号
        }
    }
    if (flag == 0)
    {
        std::cout << "账户不存在，请注册新账户" << std::endl;
        ifs.close();
        return 0;//这也属于程序正常运行
    }
    ifs.close();
    return 0;
}

void logIn::incorporate()
{
    std::cout << "请输入账户名" << std::endl;
    std::cin >> name;
    std::fstream ifs;
    std::string s;
    ifs.open("../test/Users.csv", std::ios::in);
    if (!ifs.is_open())
    {
        std::cout << "open file failed" << std::endl;
        return;
    }
    std::stringstream ss;
    std::string tmp_name; // 声明放到循环外面好一点
    while (std::getline(ifs, s))
    {
        // std::cin >> name;
        ss << s;
        std::getline(ss, tmp_name, ',');
        if (name.compare(tmp_name) == 0)
        {
            std::cout << "用户名已存在，请重新输入" << std::endl;
            std::cin >> name;
            ifs.seekg(std::ios::beg); // 回到文件开头
        }
        ss.clear(); // 记得清空
        ss.str(""); // stringstream的clear并不清空缓存，只是重置了流的状态！！！！！！！！
    } // 遇到重复的名字，文件指针就会回到开头，意味着循环重头开始
    ifs.close();


    char c;
    std::string passwordCon;
    while(1)
    {
        std::cout << "请输入密码" << std::endl;
        while ((c = _getch()) != '\r')
        {
            password += c;
            std::cout << '*';
        }
        std::cout << std::endl;
        // std::string passwordCon;             //goto返回后的重定义问题？？？？
        std::cout << "请确认密码" << std::endl;
        while ((c = _getch()) != '\r')
        {
            passwordCon += c;
            std::cout << '*';
        }
        std::cout << std::endl;
        if (passwordCon.compare(password) != 0)
        {
            std::cout << "前后密码不一致" << std::endl;//TODO:exit
            password.clear();
            passwordCon.clear();//记得清空
        }
        else
            break;
    }
    std::fstream ofs;
    ofs.open("../test/Users.csv", std::ios::out | std::ios::app);
    ofs << name << ',' << password << ',' << std::endl;
    ofs.close();
    std::cout << "注册成功，请登录" << std::endl;
}
// 尽量不要用goto语句
