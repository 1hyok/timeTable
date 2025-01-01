#include <iostream>

#include "timeTable.h"

using namespace std;

bool showMenu();
bool saveAndExit();
bool showCurriculum();
bool showPoorGrade();

int main(){
    TimeTable tT("3","1");
    //t.showTable();
    showMenu();

    return 0;
}

bool showMenu(){
    
    int menu;

    cout << "0. Exit" << endl;
    cout << "1. Curriculum" << endl;
    cout << "2. Retakable Courses" << endl;

    cout << endl << "Select menu >>> ";
    cin >> menu;

    switch (menu)
    {
    case 0:
        saveAndExit();
    case 1:
        showCurriculum();
        break;
    case 2:
        showPoorGrade();
        break;
    default:
        cout << "Selecting menu error" << endl;
        return false;
        break;
    }

    return true;
}