#include "Tasks.h"

Tasks::Tasks()
{
}

void Tasks::AddTask()
{
    while(true)
    {
        std::string title;
        std::cout << "-> Add new task (0 to exit): ";
        std::cout << std::endl;
        std::getline(std::cin, title);

        if (title == "0" || title.empty()) break;

        Task* newTask = new Task(title);
        TasksList.push_back(newTask);
    }
}

void Tasks::ShowTask(Task* object)
{
    std::string completed;
    if (object->GetIsComplete())
    {
        completed = "Complete!";
    }
    else
    {
        completed = "ToDo     ";
    }

    std::cout << completed << " | " << object->GetTitle() << std::endl;
}

void Tasks::ShowAllTasks()
{
    int count = TasksList.size();

    for (int i = 0; i < count; i++)
    {
        std::cout << i+1 << ". ";
        ShowTask(TasksList[i]);
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

void Tasks::ChangeCompleteStatus()
{
    ShowAllTasks();
    int input = -1;
    std::cout << "Which task (number, 0 to exit): ";
    std::cout << std::endl;
    std::cin >> input;
    if (input != 0)
    {
        input -= 1;
        std::cin.ignore();
        if (input >= 0 && input < TasksList.size())
        {
            TasksList[input]->SetIsComplete();
            std::cout << "-> Task: " << input+1 << ". " << TasksList[input]->GetTitle() << " - status changed" << std::endl;
        }
        else
        {
            std::cout << "-> Task number: " << input+1 << " is not exist" << std::endl;
        }
    }
}

std::vector<Task*> Tasks::GetTasksList()
{
    return TasksList;
}

void Tasks::SetTasksList(std::vector<Task *> tasksList)
{
    this->TasksList = tasksList;
}

void Tasks::DeleteTask()
{
    ShowAllTasks();
    int input = -1;
    std::cout << "Which task remove (number, 0 to exit): ";
    std::cout << std::endl;
    std::cin >> input;
    if (input != 0)
    {
        input -= 1;
        std::cin.ignore();
        if (input >= 0 && input < TasksList.size())
        {
            auto taskToRemove = TasksList.begin() + input;
            TasksList.erase(taskToRemove);
            std::cout << "-> Task: " << input+1 << " - is remove" << std::endl;
        }
        else
        {
            std::cout << "-> Task number: " << input+1 << " is not exist" << std::endl;
        }
    }
}
