#include <iostream>
#include <string>

#include "global.h"
#include "studyPlan.h"

using namespace std;

const string TAB_NAME = "Study Plan";

vector<StudyPlan> studyPlans;

bool planList();
bool addPlan();
bool deletePlan();

bool studyPlanTab() {
    int menu;
    const string menuNum = "3";

    while (1) {
        cout << endl << "<" + TAB_NAME + ">" << endl;
        cout << menuNum + "-0. Main" << endl;
        cout << menuNum + "-1. List" << endl;
        cout << menuNum + "-2. Add" << endl;
        cout << menuNum + "-3. Delete" << endl;

        cout << endl << "Select menu >>> ";
        cin >> menu;

        switch (menu) {
        case 0:
            return true;
            break;
        case 1:
            planList();
            break;
        case 2:
            addPlan();
            break;
        case 3:
            deletePlan();
            break;
        default:
            cout << "Selecting menu error" << endl;
        }
    }

    return true;
}
int printPlans() {
    int selectedPlan;
    const int plansSize = studyPlans.size();
    for (const StudyPlan &sP : studyPlans) {
        cout << sP.getIndex() << endl;
    }
    cout << endl << "Select a plan(Enter -1 to go back) >>> ";
    cin >> selectedPlan;

    if (selectedPlan > plansSize || selectedPlan < -1) {
        cout << selectedPlan << " is out of plans range " << plansSize << endl;
        return -2;
    } else {
        return selectedPlan;
    }
}