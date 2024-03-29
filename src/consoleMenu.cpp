#include "../include/consoleMenu.h"
#include "../include/utils.h"

ConsoleMenu::ConsoleMenu(Tasks* instance)
{
    this->instance = instance;
}

void ConsoleMenu::runMenu()
{
    int input = -1;
    do
    {
        displayOptions();
        input = Utils::getIntInputFromUser();

        switch (input)
        {
            case 1:
                displayFeatureTitle("Show All Tasks");
                instance->showAllTasks();
                break;
            case 2:
                displayFeatureTitle("Add New Task");
                instance->addTask();
                break;
            case 3:
                displayFeatureTitle("Complete Task");
                instance->changeCompleteStatus();
                break;
            case 4:
                displayFeatureTitle("Remove task");
                instance->deleteTask();
                break;
            case 5:
                break;
            default:
                std::cout << "-> function is not available" << std::endl;
        }

        displayFeatureEnd();

    } while(input != 5);

    std::cout << "Bye..." << std::endl;
}

void ConsoleMenu::displayOptions()
{
    std::cout << "--------- ToDo App v.0.1 --------" << std::endl;
    std::cout << "[1] Show all tasks" << std::endl;
    std::cout << "[2] Add new task" << std::endl;
    std::cout << "[3] Update task done status" << std::endl;
    std::cout << "[4] Delete task (not available)" << std::endl;
    std::cout << "[5] Exit program" << std::endl;
    displayFeatureEnd();
    std::cout << "-> Option: ";
}

void ConsoleMenu::displayFeatureTitle(std::string title)
{
//    std::cout << std::endl;
    int maxTitleSize = 32;
    int titleLength;

    titleLength = (int)title.size();
    int number = (maxTitleSize - titleLength) / 2;
    std::string separator = std::string(number, '-');

    std::cout << separator + title << separator << std::endl;
}

void ConsoleMenu::displayFeatureEnd()
{
    std::cout << std::string(32, '-') << std::endl;
}

void ConsoleMenu::pressAnyKey()
{
    std::cout << "Press any key to return..." << std::endl;
    std::cin.get();
    system("cls");
}