#include <iostream>
#include <vector>
#include "Task.h"

#ifndef TODOAPP_TASKS_H
#define TODOAPP_TASKS_H


class Tasks
{
private:
    std::vector<Task*> TasksList;
public:
    Tasks();
    void AddTask();
    void ShowTask(Task* object);
    void ShowAllTasks();
    void ChangeCompleteStatus();
    std::vector<Task*> GetTasksList();
    void SetTasksList(std::vector<Task*> tasksList);
    void DeleteTask();
};


#endif //TODOAPP_TASKS_H
