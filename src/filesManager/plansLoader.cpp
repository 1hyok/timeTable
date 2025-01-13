#include "global.h"
#include "studyPlan.h"
#include <filesystem>
#include <iostream>
#include <sstream>

namespace fs = std::filesystem;
using namespace std;

bool loadPlans() {
    int idx = 0;
    const string path = "../" + DATA_DIR + "/" + PLANS_DIR;
    try {
        for (const auto &dir : fs::directory_iterator(path)) {
            const string dirName = dir.path().filename().string();
            const string numPart = dirName.substr(PLAN_DIR.length());
            if (dirName.starts_with(PLAN_DIR) && !numPart.empty()) {
                if (numPart.find_first_not_of("0123456789") == string::npos) {
                    if (stoi(numPart) >= 0) {
                        stringstream ss;
                        ss << "Loading Plan " << idx << "..." << endl;
                        cout << ss.str() << endl;
                        StudyPlan plan = studyPlans.emplace_back(to_string(idx));
                        plan.loadTables();
                    }
                }
            }
            idx++;
        }
    } catch (const fs::filesystem_error &e) {
        cerr << "Fail to read directory" << e.path1() << " : " << e.what() << endl;
        return false;
    }
    return true;
}