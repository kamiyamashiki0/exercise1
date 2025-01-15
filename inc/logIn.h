#pragma once
#include <iostream>
#include <string>

class logIn
{
public:
    int logInMenu();
    int singIn();
    void incorporate();


    std::string name;

private:
    std::string password;
};
