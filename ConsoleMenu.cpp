#include "ConsoleMenu.h"

ConsoleMenu::ConsoleMenu(Tasks* instance)
{
    this->Instance = instance;
}

void ConsoleMenu::RunMenu()
{
    std::cout << "--------- ToDo App v.0.1 --------" << std::endl;
    char input = '-';
    while(input != '0')
    {
        DisplayOptions();
        input = '-';
        std::cin >> input;
        std::cin.ignore();
        switch (input)
        {
            case '1':
                DisplayFeatureTitle("Show All Tasks");
                Instance->ShowAllTasks();
                DisplayFeatureEnd();
                break;
            case '2':
                DisplayFeatureTitle("Add New Task");
                Instance->AddTask();
                DisplayFeatureEnd();
                break;
            case '3':
                DisplayFeatureTitle("Complete Task");
                Instance->ChangeCompleteStatus();
                DisplayFeatureEnd();
                break;
            case'4':
                DisplayFeatureTitle("Remove task");
                Instance->DeleteTask();
                DisplayFeatureEnd();
                break;
            case '0':
                break;
            default:
                std::cout << "-> function is not available" << std::endl;
        }
    }
    std::cout << "Bye..." << std::endl;
}

void ConsoleMenu::DisplayOptions()
{
    std::cout << "[1] Show all tasks" << std::endl;
    std::cout << "[2] Add new task" << std::endl;
    std::cout << "[3] Update task done status" << std::endl;
    std::cout << "[4] Delete task (not available)" << std::endl;
    std::cout << "[0] Exit program" << std::endl;
    std::cout << "-> Option: ";
}

void ConsoleMenu::DisplayFeatureTitle(std::string title)
{
    std::cout << std::endl;
    int maxTitleSize = 32;
    int titleLength;

    titleLength = (int)title.size();
    int number = (maxTitleSize - titleLength) / 2;
    std::string separator = std::string(number, '-');

    std::cout << separator + title << separator << std::endl;
}

void ConsoleMenu::DisplayFeatureEnd()
{
    std::cout << std::string(32, '-') << std::endl;
}

void ConsoleMenu::PressAnyKey()
{
    std::cout << "Press any key to return..." << std::endl;
    std::cin.get();
    system("cls");
}