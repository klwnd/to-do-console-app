#include <iostream>
#include <vector>
#include "task.h"

#ifndef TODOAPP_TASKS_H
#define TODOAPP_TASKS_H


class Tasks
{
private:
    std::vector<Task*> tasksList;
public:
    Tasks();
    void addTask();
    void showTask(Task* object);
    void showAllTasks();
    void changeCompleteStatus();
    std::vector<Task*> getTasksList();
    void setTasksList(std::vector<Task*> tasksList);
    void deleteTask();
};


#endif //TODOAPP_TASKS_H
