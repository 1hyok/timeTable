#include "studyPlan.h"

int main(){
    TimeTable t('3',"1");
    //t.showTable();
    showMenu();

    return 0;
}

bool showMenu(){
    
    int menu;

    cout << "1. Curriculum" << endl;
    cout << "2. Retakable Courses" << endl;

    cout << endl << "Select menu >>> ";
    cin >> menu;

    switch (menu)
    {
    case 1:
        showCurriculum();
        break;
    case 2:
        showPoorGrade();
        break;
    default:
        cout << "Selecting menu error" << endl;
        return false;
        break;
    }

    return true;
}

bool showCurriculum(){
    
    string gradeInput, semesterInput, currentLine, token;
    int tokenNum = 0;
    const int gradePlace = 0, semesterPos = 1;

    ifstream file(DATA_DIR + "curriculum.csv");
    if(!file){
        cerr << "Fail to open the curriculum file:" << strerror(errno) << endl;
        return false;
    }
    
    cout << "What is your grade? >>> ";
    cin >> gradeInput;
    while(1){
        cout << "What is your semester? >>> ";
        cin >> semesterInput;
        if(semesterInput == "1" || semesterInput == "2"){
            break;
        }else{
            cout << "Please enter semester as 1 or 2" << endl;
        }
    }

    cout << endl;
    getline(file, currentLine);
    cout << "===" << currentLine << "===" << endl;
    while(getline(file, currentLine)){
        stringstream ss(currentLine);
        tokenNum = -1;
        while(getline(ss, token, ',')){
            tokenNum++;
            if(tokenNum == gradePlace){
                if(token == gradeInput){
                    getline(ss, token, ',');
                    tokenNum++;
                    if (tokenNum == semesterPos){
                        if(token == semesterInput || token == "Both"){
                          cout << currentLine << endl;
                        }
                    }
                }
            }else{
                break;
            }
        }
    }

    file.close();
    return true;
}

bool showPoorGrade(){

    string currentLine, token;
    vector<string> grdArray, tmpArray;
    int tokenNum, i;

    ifstream file(DATA_DIR + "grade.csv");
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
    for(const string s : grdArray){
        cout << s << endl;
    }

    file.close();
    return true;
}