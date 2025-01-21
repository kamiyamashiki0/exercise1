#include "processControl.h"
#include "logIn.h"
#include "startMatch.h"
#include "User.h"
#include "mainMenu.h"

void processControl::exeStart()
{
    logIn login;
    mainMenu menu1;
    startMatch match;
    while(User::getInstance().status)
    {
        loginMenu(login);
        mainMenuOption(menu1, match);
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
            while (log.singIn())
                ;
            break;
        case (2):
            while (log.incorporate())
                ;
            break;
        case (0):
            log.exit();
            break;
        }
    }
}

void processControl::mainMenuOption(mainMenu &mainmenu, startMatch &start)
{
    while (User::getInstance().menuMain)
    {
        switch (int i = mainmenu.playMainMenu())
        {
        case (1):
            mainmenu.start(start);
            break;
        case (2):
            mainmenu.viewLog();
            break;
        case (3):
            mainmenu.clearLog();
            break;
        case (4):
            mainmenu.returnBack();
            break;
        case (5):
            mainmenu.logOff();
            break;
        }
    }
}
