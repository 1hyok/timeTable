#ifndef __STUDY_PLAN_
#define __STUDY_PLAN_

#include "timeTable.h"

class StudyPlan {
    private:
    const string index;
    vector<TimeTable> timeTables;

    public:
    StudyPlan(const string i) : index(i) {}
    bool addTimeTable(const TimeTable &t);
    bool showSemesters() const;
    bool saveToFiles() const;
    bool savePlan() const;
    string getIndex() const { return index; }
};

#endif