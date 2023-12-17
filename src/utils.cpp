#include "../include/utils.h"

bool Utils::isConsoleLogOn = true;

void Utils::displayInfoLog(std::string msg, bool isOk)
{
    if (isConsoleLogOn)
    {
        std::string info;
        if (isOk) info = " OK ";
        else info = "Error";

        std::cout << "  -> [" << info << "] - " << msg << std::endl;
    }
}