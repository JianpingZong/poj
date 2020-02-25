#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    double x, y;
    int counter = 1;
    while (cin >> x >> y) {
        double final_distance = sqrt(x * x + y * y);

        double current_R = 0.0;

        int year = 0;
        while (current_R < final_distance) {
            current_R = sqrt(100.00 / 3.1415926535 + current_R * current_R);
            year++;
        }

        cout << "Property " << counter++ << ": This property will begin eroding in year " << year << "." << endl;
    }

    cout << "END OF OUTPUT." << endl;

    return 0;
}