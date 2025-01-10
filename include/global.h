#ifndef __GLOBAL_H_
#define __GLOBAL_H_

#include <string>

using namespace std;

const string DATA_DIR = "data";
const string PLANS_DIR = "studyPlans";
const string PLAN_DIR = "studyPlan";
const string TABLE_DIR = "timeTable";
const string CANDIDATE_DIR = "candidates";

class StudyPlan;
extern vector<StudyPlan> studyPlans;

#endif