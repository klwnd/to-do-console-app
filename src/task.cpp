#include "../include/task.h"

Task::Task(std::string title) : title(title)
{
    isComplete = false;
}

Task::Task(std::string title, bool complete) : title(title), isComplete(complete) {}

void Task::setIsComplete()
{
    if (isComplete)
    {
        isComplete = false;
    }
    else
    {
        isComplete = true;
    }
}

std::string Task::getTitle()
{
    return title;
}

bool Task::getIsComplete()
{
    return isComplete;
}




