#include <iostream>

#ifndef TODOAPP_UTILS_H
#define TODOAPP_UTILS_H

class Utils
{
private:
    static bool isConsoleLogOn;
public:
    static void displayInfoLog(std::string msg, bool isOk);
};


#endif //TODOAPP_UTILS_H
