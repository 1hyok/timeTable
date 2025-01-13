#include <exception>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

#include "global.h"

const string MENU_NUM = "1";

bool viewCurriculum();
bool searchCourses();

bool curriculum() {
    int menu;

    while (1) {
        cout << endl << "<Curriculum>" << endl;
        cout << MENU_NUM << "-0. Main" << endl;
        cout << MENU_NUM << "-1. View Curriculum" << endl;
        cout << MENU_NUM << "-2. Search Courses" << endl;

        cout << endl << "Select menu >>> ";
        cin >> menu;

        switch (menu) {
        case 0:
            return true;
            break;
        case 1:
            viewCurriculum();
            break;
        case 2:
            searchCourses();
            break;
        default:
            cout << "Selecting menu error" << endl;
        }
    }

    return true;
}

bool viewCurriculum() {

    string gradeInput, semesterInput, currentLine, token;
    int tokenNum;
    const int gradePos = 0, semesterPos = 1;

    ifstream file("../" + DATA_DIR + "/" + "curriculum.csv");

    try {
        if (!file.is_open()) {
            throw exception();
        }
    } catch (const exception &) {
        cerr << "Fail to open the curriculum file:" << strerror(errno) << endl;
        return false;
    }

    while (1) {
        cout << "What is your grade? >>> ";
        cin >> gradeInput;
        if (gradeInput == "1" || gradeInput == "2" || gradeInput == "3" || gradeInput == "4") {
            break;
        } else {
            cout << "Please enter a grade between 1 and 4" << endl;
        }
    }
    while (1) {
        cout << "What is your semester? >>> ";
        cin >> semesterInput;
        if (semesterInput == "1" || semesterInput == "2") {
            break;
        } else {
            cout << "Please enter semester as 1 or 2" << endl;
        }
    }

    cout << endl;
    getline(file, currentLine);
    cout << "===" << currentLine << "===" << endl;
    while (getline(file, currentLine)) {
        stringstream ss(currentLine);
        tokenNum = -1;
        while (getline(ss, token, ',')) {
            tokenNum++;
            if (tokenNum == gradePos) {
                if (token == gradeInput) {
                    getline(ss, token, ',');
                    tokenNum++;
                    if (tokenNum == semesterPos) {
                        if (token == semesterInput || token == "Both") {
                            cout << currentLine << endl;
                        }
                    }
                }
            } else {
                break;
            }
        }
    }

    file.close();
    return true;
}

bool searchCourses() {
    string targetName, token, currentLine;
    ifstream file("../" + DATA_DIR + "/" + "curriculum.csv");
    int tokenNum = -1;
    const int namePos = 3;

    cout << "Enter the subject name to search:" << endl;
    cin >> targetName;

    while (getline(file, currentLine)) {
        stringstream ss(currentLine);
        tokenNum = -1;
        while (getline(ss, token, ',')) {
            tokenNum++;
            if (tokenNum == namePos) {
                if (token == targetName) {
                    cout << currentLine << endl;
                    file.close();
                    return true;
                } else {
                    break;
                }
            }
        }
    }

    cout << "Subject name does not exist." << endl;
    file.close();
    return false;
}