#include <fstream>
#include <sstream>
#include "../include/fileManager.h"
#include "../include/utils.h"

FileManager::FileManager(std::string fp)
{
    this->filePath = fp;
}

void FileManager::saveToFile(const Tasks* object)
{
    std::ofstream file;
    file.open(filePath, std::ios::trunc);

    if (file.is_open())
    {
        Utils::displayInfoLog("Load file to the memory", true);
        std::vector<Task*> tasksList = object->getTasksList();

        for (Task* element : tasksList)
        {
            file << element->getTitle() << "," << element->getIsComplete() << std::endl;
        }
        Utils::displayInfoLog("Save data to the file", true);
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
        Utils::displayInfoLog("Load file to the memory", true);

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

        Utils::displayInfoLog("Add new Task to tasksList (vector)", true);
        tasksObject->setTasksList(tasksList);
        Utils::displayInfoLog("Add tasksList to tasksObject", true);
    }
    else
    {
        Utils::displayInfoLog("File load error (file is empty or not exist)", false);
    }

    file.close();
    Utils::displayInfoLog("File closed", true);

    return tasksObject;
}