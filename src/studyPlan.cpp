#include "studyPlan.h"

bool StudyPlan::addTimeTable(const TimeTable t){
    tables.push_back(t);

    return true;
}
bool StudyPlan::showSemesters() const{
    return true;
}