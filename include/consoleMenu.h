#include <iostream>
#include "tasks.h"

#ifndef TODOAPP_CONSOLEMENU_H
#define TODOAPP_CONSOLEMENU_H


class ConsoleMenu
{
private:
    Tasks* instance;
public:
    ConsoleMenu(Tasks* instance);
    void runMenu();
    void displayOptions();
    void displayFeatureTitle(std::string title);
    void displayFeatureEnd();
    void pressAnyKey();
};


#endif //TODOAPP_CONSOLEMENU_H
