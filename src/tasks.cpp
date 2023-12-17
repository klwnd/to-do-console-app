#include "../include/tasks.h"

Tasks::Tasks()
{
}

void Tasks::addTask()
{
    while(true)
    {
        std::string title;
        std::cout << "-> Add new task (0 to exit): ";
        std::cout << std::endl;
        std::getline(std::cin, title);

        if (title == "0" || title.empty()) break;

        Task* newTask = new Task(title);
        tasksList.push_back(newTask);
    }
}

void Tasks::showTask(Task* object)
{
    std::string completed;
    if (object->getIsComplete())
    {
        completed = "Complete!";
    }
    else
    {
        completed = "ToDo     ";
    }

    std::cout << completed << " | " << object->getTitle() << std::endl;
}

void Tasks::showAllTasks()
{
    int count = tasksList.size();

    for (int i = 0; i < count; i++)
    {
        std::cout << i+1 << ". ";
        showTask(tasksList[i]);
    }

    if (count != 0)
    {
        std::cout << "Task in list: " << count << std::endl;
    }
    else
    {
        std::cout << "Task list is empty" << std::endl;
    }
}

void Tasks::changeCompleteStatus()
{
    showAllTasks();
    int input = -1;
    std::cout << "Which task (number, 0 to exit): ";
    std::cout << std::endl;
    std::cin >> input;
    if (input != 0)
    {
        input -= 1;
        std::cin.ignore();
        if (input >= 0 && input < tasksList.size())
        {
            tasksList[input]->setIsComplete();
            std::cout << "-> Task: " << input+1 << ". " << tasksList[input]->getTitle() << " - status changed" << std::endl;
        }
        else
        {
            std::cout << "-> Task number: " << input+1 << " is not exist" << std::endl;
        }
    }
}

std::vector<Task*> Tasks::getTasksList()
{
    return tasksList;
}

void Tasks::setTasksList(std::vector<Task *> tasksList)
{
    this->tasksList = tasksList;
}

void Tasks::deleteTask()
{
    showAllTasks();
    int input = -1;
    std::cout << "Which task remove (number, 0 to exit): ";
    std::cout << std::endl;
    std::cin >> input;
    if (input != 0)
    {
        input -= 1;
        std::cin.ignore();
        if (input >= 0 && input < tasksList.size())
        {
            auto taskToRemove = tasksList.begin() + input;
            tasksList.erase(taskToRemove);
            std::cout << "-> Task: " << input+1 << " - is remove" << std::endl;
        }
        else
        {
            std::cout << "-> Task number: " << input+1 << " is not exist" << std::endl;
        }
    }
}
