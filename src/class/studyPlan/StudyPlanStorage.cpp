#include "global.h"
#include "studyPlan.h"
#include <filesystem>
#include <iostream>
#include <ostream>

namespace fs = std::filesystem;

bool StudyPlan::saveToFiles() const {
    savePlan();
    for (const TimeTable &t : timeTables) {
        t.saveToFiles(index);
    }
    return true;
}
bool StudyPlan::savePlan() const {
    cout << "Saving Plan " << index << "..." << endl;
    fs::create_directory("../" + DATA_DIR + "/" + PLANS_DIR + "/" + PLAN_DIR + index);
    return true;
}
bool StudyPlan::loadTables() {
    const string path = "../" + DATA_DIR + "/" + PLANS_DIR + "/" + PLAN_DIR + index;
    const int tLength = TABLE_DIR.length();
    try {
        for (const auto &dir : fs::directory_iterator(path)) {
            const string dirName = dir.path().filename().string();
            const char gradeChar = dirName[tLength];
            const char dashChar = dirName[tLength + 1];
            const char semesterChar = dirName[tLength + 2];

            if (fs::is_directory(dir) && dirName.starts_with(TABLE_DIR) && dirName.length() == tLength + 3 &&
                dashChar == '-') {
                if (gradeChar == '1' || gradeChar == '2' || gradeChar == '3' || gradeChar == '4') {
                    if (semesterChar == '1' || semesterChar == '2' || semesterChar == 's' || semesterChar == 'w') {
                        const string gradeString = string(1, gradeChar);
                        const string semesterString = string(1, semesterChar);
                        cout << "Loading Table" << gradeString << "-" << semesterString << "..." << endl;
                        TimeTable t(gradeString, semesterString);
                        addTimeTable(t);
                        t.loadCandidate(index);
                    }
                }
            }
        }
    } catch (const fs::filesystem_error &e) {
        cerr << "Fail to read directory" << e.path1() << " : " << e.what() << endl;
        return false;
    }
    return true;
}