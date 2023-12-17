#include "include/tasks.h"
#include "include/consoleMenu.h"
#include "include/fileManager.h"

int main()
{
    fileManager fm("data.txt");
    Tasks* taskObject = fm.LoadFromFile();

    consoleMenu menu(taskObject);
    menu.RunMenu();

    fm.SaveToFile(taskObject);

    return 0;
}