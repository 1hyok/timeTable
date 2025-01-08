#ifndef __GLOBAL_H_
#define __GLOBAL_H_

#include <string>

using namespace std;

const string DATA_PATH = "../data";
const string STUDY_PLAN_PATH = "/studyPlans";
const string TIME_TABLE_PATH = "/timeTable";
const string CANDIDATE_PATH = "/candidates";

class StudyPlan;
extern vector<StudyPlan> studyPlans;

#endif