#ifndef __TIMETABLE_H_
#define __TIMETABLE_H_

#include "subject.h"
#include <vector>

const int HOURS_NUM = 10;
const int DAYS_NUM = 5;

const string dayNames[DAYS_NUM] = {"MON", "TUE", "WED", "THU", "FRI"};

class TimeTable{

    private:
        const string grade;
        const string semester;
        const int periodsNum;
        const int periodMinute;
        vector<const Subject> subjects;

        bool showDays() const;
        bool showCells() const;

        bool saveTable() const;
        bool saveCandidate(const string& studyPlanIndex) const;
    public:
        TimeTable(const string g, const string s)
            :grade(g), semester(s), periodsNum(s == "Summer" || s == "Winter" ? HOURS_NUM : HOURS_NUM * 2), periodMinute(s == "Summer" || s == "Winter" ? 60 : 30)
        {
        };

        bool showTable() const;
        bool showCandidate() const;

        Subject parseSubject(const string& line);
        bool addToCandidate(const Subject& s);

        bool saveToFiles(const string& studyPlanIndex) const;
};
#endif