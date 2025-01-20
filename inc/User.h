#pragma once
#include <string>
class User
{
public:
    static User &getInstance();
    User(const User &) = delete;
    User &operator=(const User &) = delete;
    std::string name;
    std::string password;
    int status = 0;
    bool menuLogIn = true;
    bool menuMain = false;

private:
    User() = default;
};

class people
{
public:
    people() {};
    

private:
    int id;
};

people p;
