#ifndef __STUDY_PLAN_
#define __STUDY_PLAN_

#include "timeTable.h"

class StudyPlan {
    private:
        vector<TimeTable> tables;
    public:
        StudyPlan(){

        }
        bool addTimeTable(const TimeTable t);
        bool showSemesters() const;
};

#endif