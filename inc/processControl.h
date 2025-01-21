#pragma once
#include "mainMenu.h"
#include "logIn.h"
class processControl
{
    public:
        void exeStart();
        void loginMenu(logIn &);
        void mainMenuOption(mainMenu &,startMatch&);
};
