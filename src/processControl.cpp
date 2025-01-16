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
            case(1)://今天什么都没干

        }
    }
}
