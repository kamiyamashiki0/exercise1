#include "mainMenu.h"
#include <iostream>

int mainMenu::playMainMenu()
{
    std::cout << "********************************" << std::endl;
    std::cout << "**********1.开始比赛*************" << std::endl;
    std::cout << "**********2.查看记录*************" << std::endl;
    std::cout << "**********3.清空记录*************" << std::endl;
    std::cout << "**********4.退出程序*************" << std::endl;
    std::cout << "********************************" << std::endl;
    int option;
    std::cin >> option;
    return option;
}
