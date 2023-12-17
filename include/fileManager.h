#include <iostream>
#include "tasks.h"

#ifndef TODOAPP_FILEMANAGER_H
#define TODOAPP_FILEMANAGER_H

class FileManager
{
private:
    std::string filePath;
public:
    FileManager(std::string fp);
    void saveToFile(Tasks* object);
    Tasks* loadFromFile();

};


#endif //TODOAPP_FILEMANAGER_H
