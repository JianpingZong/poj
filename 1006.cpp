#include <iostream>

using namespace std;


int main() {
    int p, e, i, d;
    int counter = 0;
    while (cin >> p >> e >> i >> d) {
        if (-1 == p) {
            return 0;
        }
        counter++;
        for (int j = d + 1;; j++) {
            if (j % 23 == p % 23 && j % 28 == e % 28 && j % 33 == i % 33) {
                cout << "Case " << counter << ": the next triple peak occurs in " << j - d << " days." << endl;
                break;
            }
        }
    }
    return 0;
}