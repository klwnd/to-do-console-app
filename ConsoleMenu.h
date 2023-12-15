#include <iostream>
#include "Tasks.h"

#ifndef TODOAPP_CONSOLEMENU_H
#define TODOAPP_CONSOLEMENU_H


class ConsoleMenu
{
private:
    Tasks* Instance;
public:
    ConsoleMenu(Tasks* instance);
    void RunMenu();
    void DisplayOptions();
    void DisplayFeatureTitle(std::string title);
    void DisplayFeatureEnd();
    void PressAnyKey();
};


#endif //TODOAPP_CONSOLEMENU_H
