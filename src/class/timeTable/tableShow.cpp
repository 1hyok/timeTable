#include <iostream>
#include <timeTable.h>

bool TimeTable::showTable() const {
    showDays();
    showCells();
    return true;
}
bool TimeTable::showDays() const {
    int i;
    int spaceNum = 10;
    int borderNum = (spaceNum * 2 + 4) * (DAYS_NUM + 1);

    string space(spaceNum, ' ');
    string border(borderNum, '-');

    cout << "Time Table" << endl;
    cout << border << endl;

    cout << "|                      |";
    for (i = 0; i < DAYS_NUM; i++) {
        cout << space << dayNames[i] << space << "|";
    }
    cout << endl;

    cout << border << endl;
    return true;
}
bool TimeTable::showCells() const {
    int row, col;
    int borderNum = 24 * (DAYS_NUM + 1);
    const int pNum = stoi(periodsNum);
    const string space(22, ' ');
    const string border(borderNum, '-');

    for (row = 0; row < pNum; row++) {
        if (row % 2 == 0) {
            for (col = 0; col < DAYS_NUM + 1; col++) {
                cout << "|" << space << "|";
            }
            cout << endl;
        } else
            cout << border << endl;
    }
    return true;
}

bool TimeTable::showCandidate() const { return true; }