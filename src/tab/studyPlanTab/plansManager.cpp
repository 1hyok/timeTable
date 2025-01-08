#include "global.h"
#include "studyPlan.h"
#include <iostream>
#include <string>

int printPlans();

bool addPlan() {
    string idx = to_string(studyPlans.size());
    studyPlans.emplace_back(idx);
    cout << "Plan " + idx + " has been added" << endl;
    return true;
}

bool deletePlan() {
    printPlans();
    return true;
}