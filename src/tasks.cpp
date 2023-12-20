#include "../include/tasks.h"
#include "../include/utils.h"

Tasks::Tasks()
{
}

void Tasks::addTask()
{
    while(true)
    {
        std::string title;
        std::cout << "-> Add new task (EMPTY to exit): ";
        std::cout << std::endl;
        std::getline(std::cin, title);

        if (title.empty()) break;

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
    input = Utils::getIntInputFromUser("Which task (number, 0 to exit): ");
    if (input != 0)
    {
        input -= 1;
        if (input >= 0 && input < tasksList.size())
        {
            tasksList[input]->setIsComplete();
            std::cout << "-> Change status task: " << input+1 << ". " << tasksList[input]->getTitle() << std::endl;
        }
        else
        {
            std::cout << "-> Task number: " << input+1 << " is not exist" << std::endl;
        }
    }
}

std::vector<Task*> Tasks::getTasksList() const
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
    input = Utils::getIntInputFromUser("Which task remove (number, 0 to exit): ");
    if (input != 0)
    {
        input -= 1;
        if (input >= 0 && input < tasksList.size())
        {
            auto taskToRemove = tasksList.begin() + input;
            std::string title = tasksList[input]->getTitle();
            tasksList.erase(taskToRemove);
            std::cout << "-> Remove task: " << input+1 << ". " << title << std::endl;
        }
        else
        {
            std::cout << "-> Task number: " << input+1 << " is not exist" << std::endl;
        }
    }
}
