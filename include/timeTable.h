#ifndef __TIMETABLE_H_
#define __TIMETABLE_H_

#include "header.h"

class TimeTable{

    private:
        const char grade;
        const string semester;
        const int periodsNum;
        const int periodMinute;

        bool showDays() const;
        bool showCells() const;

    public:
        TimeTable(const char g, const string s)
            :grade(g), semester(s), periodsNum(s == "Summer" || s == "Winter" ? HOURS_NUM : HOURS_NUM * 2), periodMinute(s == "Summer" || s == "Winter" ? 60 : 30)
        {
        };

        bool showTable() const;
        bool showCandidate() const;
};
#endif