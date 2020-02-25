#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    double mouth_out;
    double total = 0.0;
    for (int i = 0; i < 12; i++) {
        cin >> mouth_out;
        total += mouth_out;
    }
    cout << "$" << setiosflags(ios::fixed) << setprecision(2) << total /12 << endl;
    return 0;
}