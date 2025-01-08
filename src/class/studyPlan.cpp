#include "studyPlan.h"
#include <iostream>

#include "timeTable.h"

bool StudyPlan::addTimeTable(const TimeTable &tT) {
    timeTables.push_back(tT);
    return true;
}
bool StudyPlan::showSemesters() const { return true; }
// Save Function
bool StudyPlan::saveToFiles() const {
    savePlan();
    for (const TimeTable &tT : timeTables) {
        tT.saveToFiles(index);
    }
    return true;
}
bool StudyPlan::savePlan() const {
    cout << "Saving Plan " + index + "..." << endl;
    return true;
}