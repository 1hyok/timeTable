#include <iostream>
#include <string>

using namespace std;

const string TAB_NAME = "Study Plan";

int printPlans();
bool editSelectedPlan(const int selectedPlan, const string &menuNum);

bool planList() {
    const string menuNum = "3-1";

    while (1) {
        cout << endl << "<" + TAB_NAME + "-List>" << endl;
        int selectedPlan = printPlans();

        if (selectedPlan == -1) {
            return true;
        } else if (selectedPlan == -2) {
            continue;
        } else {
            editSelectedPlan(selectedPlan, menuNum);
        }
    }
}

bool editSelectedPlan(const int selectedPlan, const string &menuNum) {
    while (1) {
        int menu;
        cout << "<" + TAB_NAME + " - List - " << selectedPlan << ">" << endl;
        cout << menuNum + "-0. Back" << endl;
        cout << menuNum + "-1. Add timetables" << endl;
        cout << menuNum + "-2. Delete timetales" << endl;

        cout << endl << "Select menu >>> ";
        cin >> menu;
        switch (menu) {
        case 0:
            return true;
            break;
        case 1:
            break;
        case 2:
            break;
        default:
            cout << "Selecting menu error" << endl;
        }
    }
    return true;
}