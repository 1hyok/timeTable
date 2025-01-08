#include <iostream>

#include "timeTable.h"

using namespace std;

bool showMenu();
bool saveAndExit();
bool curriculum();
bool showPoorGrade();
bool studyPlanTab();

int main() {
    TimeTable tT("3", "1");
    // t.showTable();
    showMenu();

    return 0;
}

bool showMenu() {
    int menu = 0;
    while (1) {
        cout << endl << "<Main>" << endl;
        cout << "0. Exit" << endl;
        cout << "1. Curriculum" << endl;
        cout << "2. Retakable Courses" << endl;
        cout << "3. Study Plan" << endl;

        cout << endl << "Select menu >>> ";
        cin >> menu;

        switch (menu) {
        case 0:
            saveAndExit();
            return true;
            break;
        case 1:
            curriculum();
            break;
        case 2:
            showPoorGrade();
            break;
        case 3:
            studyPlanTab();
            break;
        default:
            cout << "Selecting menu error" << endl;
        }
    }

    return true;
}