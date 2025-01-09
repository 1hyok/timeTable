#include "studyPlan.h"
#include <global.h>
#include <iostream>

#include "timeTable.h"

bool StudyPlan::addTimeTable(const TimeTable &t) {
    timeTables.push_back(t);
    return true;
}
bool StudyPlan::showSemesters() const { return true; }
// Files Function
bool StudyPlan::saveToFiles() const {
    savePlan();
    for (const TimeTable &t : timeTables) {
        tT.saveToFiles(index);
    }
    return true;
}
bool StudyPlan::savePlan() const {
    cout << "Saving Plan " + index + "..." << endl;
    return true;
}
bool StudyPlan::loadTables() {
    int idx;
    const int totalTables = countDirs("../" + DATA_DIR + "/" + PLANS_DIR + "/" + PLAN_DIR + index, TABLE_DIR);
    for (idx = 0; idx < totalTables; idx++) {
        TimeTable &t = timeTables.emplace_back(to_string(idx));
        t.loadTables();
    }
}