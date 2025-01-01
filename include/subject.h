#ifndef __SUBJECT_H_
#define __SUBJECT_H_

#include <string>

using namespace std;

class Subject{
    private:
        const string grade, semester, korName, engName, credit, hour;
    public:
        Subject(const string g, const string s, const string k, const string e, const string c, const string h)
            :grade(g), semester(s), korName(k), engName(e), credit(c), hour(h)
        {};
        string toString() const;
};

#endif