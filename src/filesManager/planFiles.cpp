#include "global.h"
#include "studyPlan.h"
#include "timeTable.h"

int countDirs(string path, string dirName);
TimeTable &loadTables(const string planIdx);

bool loadPlans() {
    int idx;
    const int totalPlans = countDirs("../" + DATA_DIR + "/" + PLANS_DIR, PLAN_DIR);
    for (idx = 0; idx < totalPlans; idx++) {
        StudyPlan &s = studyPlans.emplace_back(to_string(idx));
        s.loadTables();
    }
    return true;
}