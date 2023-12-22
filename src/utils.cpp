#include "../include/utils.h"

// true for log info in console
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

int Utils::getIntInputFromUser()
{
    std::string stringInput;
//    std::cin >> stringInput;
//    std::cin.ignore();
    std::getline(std::cin, stringInput);
    if (stringInput.empty()) return 0; // if press enter - return 0 (exit method)

    try
    {
        int input = std::stoi(stringInput);
        return input;
    } catch (const:: std::invalid_argument& e) {
        displayInfoLog("Input is not number", false);
    } catch (const std::out_of_range& e) {
        displayInfoLog("Input is out of range int", false);
    }

    return 0;
}

int Utils::getIntInputFromUser(std::string consoleMsg)
{
    std::cout << consoleMsg;
    return getIntInputFromUser();
}