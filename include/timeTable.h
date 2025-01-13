#ifndef __TIMETABLE_H_
#define __TIMETABLE_H_

#include <vector>

#include "subject.h"

const int HOURS_NUM = 10;
const int DAYS_NUM = 5;

const string dayNames[DAYS_NUM] = {"MON", "TUE", "WED", "THU", "FRI"};

class TimeTable {
    private:
    // Variable
    const string grade;
    const string semester;
    const string periodsNum;
    const string periodMinute;
    vector<Subject> candidates;

    // Show Funtion
    bool showDays() const;
    bool showCells() const;
    // Save Function
    bool saveTable(const string &studyPlanIndex) const;
    bool saveCandidate(const string &studyPlanIndex) const;

    public:
    TimeTable(const string g, const string s)
        : grade(g), semester(s),
          periodsNum(s == "Summer" || s == "Winter" ? to_string(HOURS_NUM) : to_string(HOURS_NUM * 2)),
          periodMinute(s == "Summer" || s == "Winter" ? "60" : "30"), candidates(){};

    bool showTable() const;
    bool showCandidate() const;

    Subject parseSubject(const string &line) const;
    bool addCandidate(const Subject &s);

    bool saveToFiles(const string &studyPlanIndex) const;
    bool loadCandidate(const string &studyPlanIndex);
};
#endif