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
        return;
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
            std::string tmp_password;
            char c;
            std::getline(ss, tmp_password, ',');
            while(1)
            {
                while((c=_getch())!='\r')
                {
                    password += c;
                    std::cout << '*';
                }
                std::cout << std::endl;
                if(password.compare(tmp_password)==0)
                {
                    std::cout << "登录成功" << std::endl;
                    break;
                }
                else
                {
                    std::cout << "密码错误，请重新输入" << std::endl;//TODO:exit
                    password.clear();
                }                              //重新输入时之前的输入要清空
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
    ifs.close();
}

void logIn::incorporate()
{
    std::cout << "请输入账户名" << std::endl;
    lableIn:
    std::cin >> name;
    std::fstream ifs;
    std::string s;
    ifs.open("../test/Users.csv", std::ios::in);
    if(!ifs.is_open())
    {
        std::cout << "open file failed" << std::endl;
        return;
    }
    while(std::getline(ifs,s))
    {
        std::stringstream ss;
        ss << s;
        std::string tmp_name;
        std::getline(ss, tmp_name, ',');
        if(name.compare(tmp_name)==0)
        {
            std::cout << "用户名已存在，请重新输入" << std::endl;
            ifs.close();
            goto lableIn;
        }
    }
    ifs.close();

    lablePassRein:
    std::cout << "请输入密码" << std::endl;
    char c;
    while((c=_getch())!='\r')
    {
        password += c;
        std::cout << '*';
    }
    std::cout << std::endl;
    std::string passwordCon;             //goto返回后的重定义问题？？？？
    std::cout << "请确认密码" << std::endl;
    while((c=_getch())!='\r')
    {
        passwordCon += c;
        std::cout << '*';
    }
    std::cout << std::endl;
    if(passwordCon.compare(password)!=0)
    {
        std::cout << "前后密码不一致" << std::endl;
        goto lablePassRein;
    }
    std::fstream ofs;
    ofs.open("../test/Users.csv", std::ios::out | std::ios::app); 
    ofs << name << ',' << password << ',' << std::endl;
    ofs.close();
    std::cout << "注册成功，请登录" << std::endl;
}
