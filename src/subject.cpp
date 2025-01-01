#include "subject.h"

string Subject::toString() const {
    return grade + "," + semester + "," + korName + "," + engName + "," + credit + "," + hour;
}