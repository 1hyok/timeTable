#include <iostream>

#include "global.h"
#include "studyPlan.h"

using namespace std;

bool saveAndExit() {
    for (const StudyPlan &sP : studyPlans) {
        sP.saveToFiles();
    }
    cout << "Exiting..." << endl;
    return true;
}