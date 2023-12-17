#include <iostream>
#include "tasks.h"

#ifndef TODOAPP_CONSOLEMENU_H
#define TODOAPP_CONSOLEMENU_H


class consoleMenu
{
private:
    Tasks* Instance;
public:
    consoleMenu(Tasks* instance);
    void RunMenu();
    void DisplayOptions();
    void DisplayFeatureTitle(std::string title);
    void DisplayFeatureEnd();
    void PressAnyKey();
};


#endif //TODOAPP_CONSOLEMENU_H
