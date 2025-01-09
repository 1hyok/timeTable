#ifndef __GLOBAL_H_
#define __GLOBAL_H_

#include <filesystem>
#include <string>

using namespace std;
namespace fs = std::filesystem;

const string DATA_DIR = "../data";
const string PLANS_DIR = "/studyPlans";
const string PLAN_DIR = "/studyPlan";
const string TABLE_DIR = "/timeTable";
const string CANDIDATE_DIR = "/candidates";

class StudyPlan;
extern vector<StudyPlan> studyPlans;

inline int countDirs(string path, string dirName) {
    int count = 0;
    for (const auto &dir : fs::directory_iterator(path)) {
        if (fs::is_directory(dir) && dir.path().filename().string().starts_with(dirName)) {
            count++;
        }
    }
    return count;
}

#endif