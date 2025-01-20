#include "User.h"

User &User::getInstance() // 在类外定义时，函数实现已经绑定到类成员函数的声明，编译器知道它的静态性质，因此无需重复声明 static
{
    static User user;
    //return &user;非常量引用的初始值必须为左值→左值引用不能引用右值，除非加const修饰
    return user;
}
