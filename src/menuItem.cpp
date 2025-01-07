#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>

#include "studyPlan.h"
#include "global.h"

using namespace std;

vector<StudyPlan> studyPlans;


bool saveAndExit(){
    for(const StudyPlan& sP : studyPlans){
        sP.save();
    }
    return true;
}
bool showPoorGrade(){

    string currentLine, token;
    vector<string> grdArray, tmpArray;
    int tokenNum, i;

    ifstream file(DATA_PATH + "/grade.csv");
    if(!file){
        cerr << "Fail to open the grade file:" << strerror(errno) << endl;
        return false;
    }

    cout << endl;
    cout << "<Poor Subjects>" << endl;
    getline(file, currentLine);
    cout << "===" << currentLine << "===" << endl;
    while(getline(file, currentLine)){
        stringstream ss(currentLine);
        tokenNum = -1;
        while(getline(ss, token, ',')){
            tokenNum++;
            if(tokenNum == 6){
                if(token.length() == 1 && isalpha(token[0])){
                    continue;
                }else if(token.length() == 3 && token[1] == '.'){
                    if(stof(token) <= 2.5 ){
                        grdArray.push_back(currentLine);
                        continue;
                    }
                }else{
                    cout << "Grade Format Error" << endl;
                    return false;
                }
            }
        }
    }

    cout << "Major Electives" << endl;
    tmpArray = grdArray;
    for(i = 0; i < tmpArray.size(); i++){
        stringstream ss(tmpArray[i]);
        tokenNum = -1;
        while(getline(ss, token, ',')){
            tokenNum++;
            if(tokenNum == 2){
                if(token == "ME"){
                    cout << tmpArray[i] << endl;
                    grdArray.erase(grdArray.begin() + i);
                }
            }
        }
    }

    cout << "The Others" << endl;
    // for(i = 0; i < grdArray.size(); i++){
    //     cout << grdArray[i] << endl;
    // }
    for(const string& s : grdArray){
        cout << s << endl;
    }

    file.close();
    return true;
}
bool showStudyPlan(){
    return true;
}