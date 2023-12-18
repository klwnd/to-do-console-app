#include "include/tasks.h"
#include "include/consoleMenu.h"
#include "include/fileManager.h"

int main()
{
    FileManager fm("data.txt");
    Tasks* taskObject = fm.loadFromFile();

    ConsoleMenu menu(taskObject);
    menu.runMenu();

    fm.saveToFile(taskObject);

    delete taskObject;

    return 0;
}