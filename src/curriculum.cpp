#include <string>
#include <fstream>
#include <iostream>
#include <sstream>

#include "global.h"

bool curriculumTab(){
    while(1){
        
    }
}

bool showCurriculum(){
    
    string gradeInput, semesterInput, currentLine, token;
    int tokenNum = 0;
    const int gradePos = 0, semesterPos = 1;

    ifstream file(DATA_PATH + "/curriculum.csv");
    if(!file){
        cerr << "Fail to open the curriculum file:" << strerror(errno) << endl;
        return false;
    }
    
    while(1){
        cout << "What is your grade? >>> ";
        cin >> gradeInput;
        if(gradeInput == "1" || gradeInput == "2" || gradeInput == "3" || gradeInput == "4"){
            break;
        }else{
            cout << "Please enter a grade between 1 and 4" << endl;
        }
    }
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
            if(tokenNum == gradePos){
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

bool searchCourse(){
    string targetName, token, currentLine;
    ifstream file(DATA_PATH + "/curriculum.csv");
    int tokenNum = 0;
    const int namePos = 3;

    cout << "Enter the subject name to search:" << endl;
    cin >> targetName;

    while(getline(file, currentLine)){
        stringstream ss(currentLine);
        while(getline(ss, token, ',')){
            tokenNum++;
            if(tokenNum == namePos){
                if(token == targetName){
                    cout << currentLine << endl;
                    file.close();
                    return true;
                }else{
                    break;
                }
            }
        }
    }

    cout << "Subject name does not exist." << endl;
    file.close();
    return false;
}