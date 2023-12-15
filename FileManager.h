#include <iostream>
#include "Tasks.h"
#ifndef TODOAPP_FILEMANAGER_H
#define TODOAPP_FILEMANAGER_H


class FileManager
{
private:
    std::string FilePath;
    bool IsConsoleLogOn;
public:
    FileManager(std::string fp);
    void SaveToFile(Tasks* object);
    Tasks* LoadFromFile();
    void DisplayInfoLog(std::string msg, bool check);

};


#endif //TODOAPP_FILEMANAGER_H
