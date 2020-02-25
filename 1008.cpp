#include <iostream>

using namespace std;

int main() {
    char *month[] = {"imix", "ik", "akbal", "kan", "chicchan", "cimi", "manik", "lamat", "muluk", "ok", "chuen", "eb",
                     "ben", "ix", "mem", "cib", "caban", "eznab", "canac", "ahau"};
    int n;
    cin >> n;
    cout << n << endl;
    while (n--) {
        int dd;
        char mm[7];
        int yy;
        char nonsense;
        cin >> dd >> nonsense >> mm >> yy;

        int totol_days = 365 * yy;
        switch (mm[0]) {
            case 'p':
                switch (mm[1]) {
                    case 'o':
                        totol_days += 20 * 0;
                        break;
                    case 'a':
                        totol_days += 20 * 15;
                        break;
                }
                break;
            case 'n':
                totol_days += 20 * 1;
                break;
            case 'z':
                switch (mm[1]) {
                    case 'i':
                        totol_days += 20 * 2;
                        break;
                    case 'o':
                        totol_days += 20 * 3;
                        break;
                    case 'a':
                        totol_days += 20 * 10;
                        break;
                }
                break;
            case 't':
                totol_days += 20 * 4;
                break;
            case 'x':
                totol_days += 20 * 5;
                break;
            case 'y':
                switch (mm[1]) {
                    case 'o':
                        totol_days += 20 * 6;
                        break;
                    case 'a':
                        totol_days += 20 * 9;
                        break;
                }
                break;
            case 'm':
                switch (mm[1]) {
                    case 'o':
                        totol_days += 20 * 7;
                        break;
                    case 'a':
                        totol_days += 20 * 12;
                        break;
                    case 'u':
                        totol_days += 20 * 14;
                        break;
                }
                break;
            case 'c':
                switch (mm[1]) {
                    case 'h':
                        totol_days += 20 * 8;
                        break;
                    case 'e':
                        totol_days += 20 * 11;
                        break;
                    case 'u':
                        totol_days += 20 * 17;
                        break;
                }
                break;
            case 'k':
                switch (mm[1]) {
                    case 'a':
                        totol_days += 20 * 13;
                        break;
                    case 'o':
                        totol_days += 20 * 16;
                        break;
                }
                break;
            case 'u':
                totol_days += 20 * 18;
                break;
        }
        totol_days += dd;

        cout << totol_days % 13 + 1 << " " << month[totol_days % 20] << " " << totol_days / 260 << endl;
    }
    return 0;
}