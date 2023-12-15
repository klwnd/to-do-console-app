#include "Tasks.h"
#include "ConsoleMenu.h"
#include "FileManager.h"

int main()
{
    FileManager fm("data.txt");
    Tasks* taskObject = fm.LoadFromFile();

    ConsoleMenu menu(taskObject);
    menu.RunMenu();

    fm.SaveToFile(taskObject);

    return 0;
}