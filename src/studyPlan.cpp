#include "studyPlan.h"
#include "timeTable.h"

bool StudyPlan::addTimeTable(const TimeTable& tT){
    timeTables.push_back(tT);
    return true;
}
bool StudyPlan::showSemesters() const{
    return true;
}
bool StudyPlan::save() const{
    for(const TimeTable& tT : timeTables){
        tT.saveToFiles(index);
    }
    return true;
}