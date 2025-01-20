#pragma once
#include <iostream>
#include <string>

class logIn
{
public:
    int logInMenu();
    int singIn();
    int incorporate();
    void exit();

    std::string name;


private:
    std::string password;
};
