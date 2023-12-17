#include <fstream>
#include <sstream>
#include "../include/fileManager.h"

fileManager::fileManager(std::string fp)
{
    this->FilePath = fp;
    IsConsoleLogOn = true;
}

void fileManager::SaveToFile(Tasks* object)
{
    std::ofstream file;
    file.open(FilePath, std::ios::trunc);

    if (file.is_open())
    {
        DisplayInfoLog("Load file to the memory", true);
        std::vector<Task*> tasksList = object->GetTasksList();

        for (Task* element : tasksList)
        {
            file << element->GetTitle() << "," << element->GetIsComplete() << std::endl;
        }
        DisplayInfoLog("Save data to the file", true);
    }

    file.close();
}

Tasks* fileManager::LoadFromFile()
{
    Tasks* tasksObject = new Tasks;
    std::vector<Task*> tasksList;

    std::fstream file;
    file.open(FilePath, std::ios::in);
    if (file.is_open() && file.peek() != EOF)
    {
        DisplayInfoLog("Load file to the memory", true);

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

        DisplayInfoLog("Add new Task to tasksList (vector)", true);
        tasksObject->SetTasksList(tasksList);
        DisplayInfoLog("Add tasksList to tasksObject", true);
    }
    else
    {
        DisplayInfoLog("File load error (file is empty or not exist)", false);
    }

    file.close();
    DisplayInfoLog("File closed", true);

    return tasksObject;
}

void fileManager::DisplayInfoLog(std::string msg, bool check)
{
    if (IsConsoleLogOn)
    {
        std::string info;
        if (check) info = "Done";
        else info = "Error";

        std::cout << "  -> [" << info << "] - " << msg << std::endl;
    }
}