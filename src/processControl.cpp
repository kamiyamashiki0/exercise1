#include "processControl.h"
#include "logIn.h"
#include "startMatch.h"
#include "User.h"
#include "mainMenu.h"

void processControl::exeStart()
{
    logIn login;
    while (int i = login.logInMenu())
    {
        switch (i)
        {
        case (1):
            while (login.singIn())
                ;
        }
    }
}

void processControl::loginMenu(logIn &log)
{
    // 单例模式
    while (User::getInstance().menuLogIn)
    {
        switch (int i = log.logInMenu())
        {
        case (1):
            while (log.singIn());
            break;
        case (2):
            while (log.incorporate());
            break;
        case (0):
            log.exit();
            break;
        }
    }
}

void processControl::mainMenuOption(mainMenu& mainmenu)
{
    while(User::getInstance().menuMain)
    {
        
    }
}
