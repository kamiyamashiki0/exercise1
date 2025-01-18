#include "processControl.h"
#include "logIn.h"
#include "startMatch.h"

void processControl::exeStart()
{
    logIn login;
    while(int i=login.logInMenu())
    {
        switch(i)
        {
            case(1):
                while(login.singIn());
                
        }
    }
}

void processControl::loginMenu(const player& p)
{
    //单例模式
}
