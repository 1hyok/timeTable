#include "studyPlan.h"
#include <global.h>

#include "timeTable.h"

bool StudyPlan::addTimeTable(const TimeTable &t) {
    timeTables.push_back(t);
    return true;
}
bool StudyPlan::showSemesters() const { return true; }