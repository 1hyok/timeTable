#include "global.h"
#include "studyPlan.h"
#include <filesystem>
#include <iostream>

namespace fs = std::filesystem;
using namespace std;

bool loadPlans() {
    int idx = 0;
    const string path = "../" + DATA_DIR + "/" + PLANS_DIR;
    for (const auto &dir : fs::directory_iterator(path)) {
        const string dirName = dir.path().filename().string();
        const string numPart = dirName.substr(PLAN_DIR.length());
        if (dirName.starts_with(PLAN_DIR) && !numPart.empty()) {
            if (numPart.find_first_not_of("0123456789") == string::npos) {
                if (stoi(numPart) >= 0) {
                    cout << "Loading Plan " + to_string(idx) + "..." << endl;
                    StudyPlan plan = studyPlans.emplace_back(to_string(idx));
                    plan.loadTables();
                }
            }
        }
        idx++;
    }
    return true;
}