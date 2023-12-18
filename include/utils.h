#include <iostream>

#ifndef TODOAPP_UTILS_H
#define TODOAPP_UTILS_H

class Utils
{
private:
    static bool isConsoleLogOn;
public:
    static void displayInfoLog(std::string msg, bool isOk);
    static int getIntInputFromUser();
    static int getIntInputFromUser(std::string consoleMsg);
};

#endif //TODOAPP_UTILS_H
