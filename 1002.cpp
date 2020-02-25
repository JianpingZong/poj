#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<string> ls;

    while (n--) {
        string s;
        cin >> s;

        string actual_num = "";
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '-') {
                continue;
            } else if (s[i] >= 'A' && s[i] < 'Z') {
                char turning = (s[i] - 'A' - (s[i] > 'Q')) / 3 + '2';
                actual_num = actual_num + turning;
            } else {
                actual_num = actual_num + s[i];
            }
        }

        ls.push_back(actual_num);
    }

    sort(ls.begin(), ls.end());

    bool valid = false;
    for (int i = 0, counter = 1; i < ls.size(); i += counter, counter = 1) {
        while (i + counter < ls.size() && ls.at(i) == ls.at(i + counter)) {
            counter ++;
        }
        if (counter > 1) {
            valid = true;
            cout << ls[i].substr(0, 3) << "-" << ls[i].substr(3, 7) << " " << counter << endl;
        }
    }

    if (!valid) {
        cout << "No duplicates." << endl;
    }

    return 0;
}