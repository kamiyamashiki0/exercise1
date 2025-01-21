#include "mainMenu.h"
#include <iostream>
#include "startMatch.h"
#include <fstream>
#include <string>
#include "User.h"

int mainMenu::playMainMenu()
{
    std::cout << "********************************" << std::endl;
    std::cout << "**********1.开始比赛*************" << std::endl;
    std::cout << "**********2.查看记录*************" << std::endl;
    std::cout << "**********3.清空记录*************" << std::endl;
    std::cout << "**********4.返回上级*************" << std::endl;
    std::cout << "**********5.退出程序*************" << std::endl;
    std::cout << "********************************" << std::endl;
    int option;
    std::cin >> option;
    return option;
}

void mainMenu::start(startMatch& match)
{
    match.createScore(12);
    match.createPlayer();
    match.match();
}

void mainMenu::viewLog()
{
    std::string fileName = User::getInstance().name;
    fileName += "Log.csv";
    std::string filepath = "../test/" + fileName;
    std::fstream ifs;
    ifs.open(filepath, std::ios::in);
    if(!ifs.is_open())
    {
        std::cout << "该用户无历史记录" << std::endl;
        return;
    }
    std::string s;
    while(std::getline(ifs,s))
    {
        std::cout << s << std::endl;
    }
    ifs.close();
}

void mainMenu::clearLog()
{
    std::string fileName = User::getInstance().name;
    fileName += "Log.csv";
    std::string filepath = "../test/" + fileName;
    std::fstream ofs;
    ofs.open(filepath, std::ios::out);//清空文件
    ofs.close();
}

void mainMenu::logOff()
{
    User::getInstance().status = 1;
    User::getInstance().menuMain = false;
    User::getInstance().menuLogIn = false;
}

void mainMenu::returnBack()
{
    User::getInstance().menuLogIn = true;
    User::getInstance().menuMain = false;
}
