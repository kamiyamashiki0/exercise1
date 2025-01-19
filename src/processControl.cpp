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

void processControl::loginMenu(logIn& log)
{
    //单例模式
    while(log.status)
    {
        switch(int i=log.logInMenu())
        {
            case(1):
            while(log.singIn());
            break;
            case(2):
            
        }
    }
}
