#include <fstream>
#include <sstream>
#include "../include/fileManager.h"

FileManager::FileManager(std::string fp)
{
    this->filePath = fp;
    isConsoleLogOn = true;
}

void FileManager::saveToFile(Tasks* object)
{
    std::ofstream file;
    file.open(filePath, std::ios::trunc);

    if (file.is_open())
    {
        displayInfoLog("Load file to the memory", true);
        std::vector<Task*> tasksList = object->getTasksList();

        for (Task* element : tasksList)
        {
            file << element->getTitle() << "," << element->getIsComplete() << std::endl;
        }
        displayInfoLog("Save data to the file", true);
    }

    file.close();
}

Tasks* FileManager::loadFromFile()
{
    Tasks* tasksObject = new Tasks;
    std::vector<Task*> tasksList;

    std::fstream file;
    file.open(filePath, std::ios::in);
    if (file.is_open() && file.peek() != EOF)
    {
        displayInfoLog("Load file to the memory", true);

        std::string line;

        while (std::getline(file, line))
        {
            int counter = 0;
            std::istringstream ss(line);
            std::string token;
            std::string data[2];

            while(std::getline(ss, token, ','))
            {
                data[counter] = token;
                counter++;
            }

            tasksList.push_back(new Task(data[0], std::stoi(data[1])));

        }

        displayInfoLog("Add new Task to tasksList (vector)", true);
        tasksObject->setTasksList(tasksList);
        displayInfoLog("Add tasksList to tasksObject", true);
    }
    else
    {
        displayInfoLog("File load error (file is empty or not exist)", false);
    }

    file.close();
    displayInfoLog("File closed", true);

    return tasksObject;
}

void FileManager::displayInfoLog(std::string msg, bool check)
{
    if (isConsoleLogOn)
    {
        std::string info;
        if (check) info = "Done";
        else info = "Error";

        std::cout << "  -> [" << info << "] - " << msg << std::endl;
    }
}