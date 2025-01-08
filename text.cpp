#include <iostream>

using namespace std;

int main() {
    int selectedPlan;
    cout << endl << "Select a plan(Enter -1 to go back) >>> ";
    cin >> selectedPlan;

    if ((selectedPlan > 2 - 1) || (selectedPlan < -1)) {
        cout << selectedPlan << " is out of plans range " << 2 << endl;
        return -2;
    } else {
        return selectedPlan;
    }
}