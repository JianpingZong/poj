#include <iostream>

using namespace std;

int main() {
    double out_cards;
    while (cin >> out_cards) {
        if (out_cards - 0.00 < 0.000001) {
            continue;
        }
        int cards_num = 1;
        while (out_cards > 0) {
            out_cards -= 1.0 / double(cards_num++ + 1);
        }
        cout << cards_num - 1 << " card(s)" << endl;
    }
    return 0;
}