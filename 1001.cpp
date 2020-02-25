#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>

using namespace std;

string plusplus(string num_one, string num_two) {
    string a, b;
    if (num_one.length() > num_two.length()) {
        a = num_one;
        b = num_two;
    } else {
        b = num_one;
        a = num_two;
    }

    reverse(b.begin(), b.end());
    b.append(a.length() - b.length(), '0');
    reverse(b.begin(), b.end());

    int flag = 0;
    int calculate_position = a.length();
    while (calculate_position--) {
        a[calculate_position] = a[calculate_position] + b[calculate_position] - 48 + flag;
        if (a[calculate_position] > '9') {
            a[calculate_position] = a[calculate_position] - 10;
            flag = 1;
        } else {
            flag = 0;
        }
    }

    if (flag) {
        a = "1" + a;
    }

    return a;
}


string multmult(string num_one, string num_two) {
    string a, b;
    if (num_one.length() > num_two.length()) {
        a = num_one;
        b = num_two;
    } else {
        b = num_one;
        a = num_two;
    }

    string rtn_rst = "0";
    for (int i = b.length() - 1; i >= 0; i--) {
        int flag = 0;
        string tmp_rst = "";
        for (int j = a.length() - 1; j >= 0; j--) {
            int camp = (a[j] - 48) * (b[i] - 48) + flag;

            stringstream ss;
            ss << camp % 10;
            tmp_rst = ss.str() + tmp_rst;
            flag = camp / 10;
        }
        if (flag) {
            stringstream ss;
            ss << flag;
            tmp_rst = ss.str() + tmp_rst;
        }
        rtn_rst = plusplus(rtn_rst, tmp_rst.append(b.length() - i - 1, '0'));
    }

    return rtn_rst;
}


int main() {
    string s;
    int n;

    while (cin >> s >> n) {
        int dot_position = s.find('.');
        int final_dot_position = n * (5 - dot_position);
        s = s.substr(0, dot_position) + s.substr(dot_position + 1, s.length());

        string rst = "1";
        while (n--) {
            rst = multmult(rst, s);
        }
        rst.insert(rst.length() - final_dot_position, 1, '.');

        while (rst[0] == '0') {
            rst = rst.substr(1, rst.length());
        }
        while (rst[rst.length() - 1] == '0') {
            rst = rst.substr(0, rst.length() - 1);
        }

        if (rst[rst.length() - 1] == '.') {
            rst = rst.substr(0, rst.length() - 1);
        }

        cout << rst << endl;
    }

    return 0;
}