#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <cstring>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

const string DATA_DIR = "./data/";

const int HOURS_NUM = 10;
const int DAYS_NUM = 5;

const string dayNames[DAYS_NUM] = {"MON", "TUE", "WED", "THU", "FRI"};

bool showMenu();
bool showCurriculum();
bool showPoorGrade();

#endif