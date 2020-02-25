#include <iostream>

using namespace std;

struct one_string {
    char lt[51];
    int rev;
};

int main() {
    int n, m;
    cin >> m >> n;

    one_string row[100];
    for (int i = 0; i < n; i++) {
        cin >> row[i].lt;
        row[i].rev = 0;
        for (int j = 0; j < m; j++) {
            for (int k = j + 1; k < m; k++) {
                if (row[i].lt[j] > row[i].lt[k]) {
                    row[i].rev++;
                }
            }
        }
    }

    one_string temp;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (row[i].rev > row[j].rev) {
                temp = row[i];
                row[i] = row[j];
                row[j] = temp;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << row[i].lt[j];
        }
        cout << endl;
    }


    return 0;
}