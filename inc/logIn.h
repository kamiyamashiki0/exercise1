#pragma once
#include <iostream>
#include <string>

class logIn
{
public:
    int logInMenu();
    int singIn();
    void incorporate();
    void exit();

    std::string name;
    int status = 1;

private:
    std::string password;
};
