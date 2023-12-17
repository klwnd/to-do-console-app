#include <iostream>

#ifndef TODOAPP_TASK_H
#define TODOAPP_TASK_H

class Task
{
private:
    std::string title;
    bool isComplete;
public:
    Task(std::string title);
    Task(std::string title, bool complete);
    std::string getTitle();
    bool getIsComplete();
    void setIsComplete();
};


#endif //TODOAPP_TASK_H
