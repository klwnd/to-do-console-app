#include <iostream>
#ifndef TODOAPP_TASK_H
#define TODOAPP_TASK_H

class Task
{
private:
    std::string Title;
    bool IsComplete;
public:
    Task(std::string title);
    Task(std::string title, bool complete);
    std::string GetTitle();
    bool GetIsComplete();
    void SetIsComplete();
};


#endif //TODOAPP_TASK_H
