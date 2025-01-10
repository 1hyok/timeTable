#include "global.h"
#include "subject.h"
#include "timeTable.h"
#include <cstring>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>

namespace fs = std::filesystem;

bool TimeTable::saveToFiles(const string &studyPlanIndex) const {
    saveTable(studyPlanIndex);
    saveCandidate(studyPlanIndex);
    return true;
};
bool TimeTable::saveTable(const string &studyPlanIndex) const {
    const string info = periodsNum + "," + periodMinute;
    const string name = grade + "-" + semester;
    const string tablePath =
        "../ " + DATA_DIR + " / " + PLANS_DIR + " / " + PLAN_DIR + studyPlanIndex + " /" + TABLE_DIR + name;

    fs::create_directory(tablePath);
    fs::create_directory(tablePath + "/candidates");

    ofstream file(tablePath + " / " + "info.csv");
    if (!file) {
        cerr << "Fail to open timeTable" + name + "/info.csv for writing: " << strerror(errno) << endl;
        return false;
    }

    cout << "Saving Table " + name + "..." << endl;
    file << info << endl;
    file.close();
    return true;
};
bool TimeTable::saveCandidate(const string &studyPlanIndex) const {
    for (const Subject &s : candidates) {
        s.saveToFiles(studyPlanIndex, grade, semester);
    }
    return true;
};

bool TimeTable::loadCandidate(const string &studyPlanIndex) {
    int i;
    const string candidatePath = "../" + DATA_DIR + "/" + PLANS_DIR + "/" + PLAN_DIR + studyPlanIndex + "/" +
                                 TABLE_DIR + grade + "-" + semester + "/" + CANDIDATE_DIR;
    for (const auto &csv : fs::directory_iterator(candidatePath)) {
        if (fs::is_regular_file(csv) && csv.path().extension() == ".csv") {
            if (csv.path().extension() == "csv") {
                ifstream file(csv.path());
                string line, token;

                if (!file) {
                    cerr << "Fail to open " + csv.path().string() + ":" + strerror(errno) << endl;
                    return false;
                }

                if (!getline(file, line)) {
                    file.close();
                    return false;
                }
                Subject s = parseSubject(line);
                cout << "Loading Candidate" + s.getGrade() + "..." << endl;
                addCandidate(s);
            }
        }
    }
    return true;
};