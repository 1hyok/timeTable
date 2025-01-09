#ifndef __STUDY_PLAN_
#define __STUDY_PLAN_

#include "timeTable.h"

class StudyPlan {
    private:
    const string index;
    vector<TimeTable> timeTables;

    public:
    StudyPlan(const string i) : index(i) {}
    string getIndex() const { return index; }
    bool addTimeTable(const TimeTable &t);
    bool showSemesters() const;

    bool saveToFiles() const;
    bool savePlan() const;
    bool loadTables();
};

#endif