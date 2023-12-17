#include <iostream>
#include "tasks.h"
#ifndef TODOAPP_FILEMANAGER_H
#define TODOAPP_FILEMANAGER_H


class FileManager
{
private:
    std::string filePath;
    bool isConsoleLogOn;
public:
    FileManager(std::string fp);
    void saveToFile(Tasks* object);
    Tasks* loadFromFile();
    void displayInfoLog(std::string msg, bool check);

};


#endif //TODOAPP_FILEMANAGER_H
