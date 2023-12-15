#include "Task.h"

Task::Task(std::string title) : Title(title)
{
    IsComplete = false;
}

Task::Task(std::string title, bool complete) : Title(title), IsComplete(complete) {}

void Task::SetIsComplete()
{
    if (IsComplete)
    {
        IsComplete = false;
    }
    else
    {
        IsComplete = true;
    }
}

std::string Task::GetTitle()
{
    return Title;
}

bool Task::GetIsComplete()
{
    return IsComplete;
}




