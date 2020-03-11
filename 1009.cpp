#include <iostream>
#include <algorithm>

using namespace std;

#define MOST_PAIRS 1010

struct pixel{
    int val;
    int pos;
};

int get_pixel_value(int row, int col, int width, int run_length[], int pixel_value[]);
int max_abs_diff(int row, int col, int total_pixel, int width, int run_length[], int pixel_value[]);
int comp(pixel a, pixel b);

int main() {
    pixel result[9 * MOST_PAIRS];
    int pixel_value[MOST_PAIRS];
    int run_length[MOST_PAIRS];

    int width;
    while (cin >> width && width != 0) {
        cout << width << endl;

        int pair_counter = 0;
        int total_pixel = 0;
        while (cin >> pixel_value[pair_counter] >> run_length[pair_counter] && run_length[pair_counter] != 0) {
            total_pixel += run_length[pair_counter++];
        }

        int pixel_pointer = 0;
        int pair_pointer = 0;
        int result_pointer = 0;
        while (pixel_pointer < total_pixel) {
            int row = pixel_pointer / width;
            int col = pixel_pointer % width;
            for (int i = row - 1; i <= row + 1; ++i) {
                for (int j = col - 1; j <= col + 1; ++j) {
                    if (i < 0 || j < 0 || i >= total_pixel / width || j >= width) {
                        continue;
                    }
                    result[result_pointer].val = max_abs_diff(i, j, total_pixel, width, run_length, pixel_value);
                    result[result_pointer++].pos = i * width + j;
                }
            }
            pixel_pointer += run_length[pair_pointer++];
        }
        result[result_pointer].val = max_abs_diff(total_pixel / width - 1, 0, total_pixel, width, run_length, pixel_value);
        result[result_pointer++].pos = total_pixel - width;
        sort(result, result + result_pointer, comp);

        for (int i = 0; i < result_pointer;) {
            cout << result[i].val << " ";
            int j = i + 1;
            while (result[i].val == result[j].val && j < result_pointer) {
                ++j;
            }
            if (j == result_pointer) {
                cout << total_pixel - result[i].pos << endl;
            } else {
                cout << result[j].pos - result[i].pos << endl;
            }
            i = j;
        }
        cout << "0 0" << endl;
    }
    cout << width << endl;

    return 0;
}

int get_pixel_value(int row, int col, int width, int run_length[], int pixel_value[]) {
    int pos = row * width + col;
    int i = 0;
    while (pos >= 0) {
        pos -= run_length[i++];
    }
    return pixel_value[i - 1];
}

int max_abs_diff(int row, int col, int total_pixel, int width, int run_length[], int pixel_value[]) {
    int pix_val = get_pixel_value(row, col, width, run_length, pixel_value);
    int max_val = 0;
    for (int i = row - 1; i <= row + 1; ++i) {
        for (int j = col - 1; j <= col + 1; ++j) {
            if (i < 0 || j < 0 || i >= total_pixel / width || j >= width || (i == row && j == col)) {
                continue;
            }
            int abs_diff = abs(pix_val - get_pixel_value(i, j, width, run_length, pixel_value));
            max_val = max(max_val, abs_diff);
        }
    }
    return max_val;
}

int comp(pixel a, pixel b) {
    return a.pos < b.pos;
}
