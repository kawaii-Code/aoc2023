#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

#ifndef PART2
#define PART1
#endif

int h;
int w;

bool inrange(int i, int j) {
    return 0 <= i && i < h && 0 <= j && j < w;
}

bool issymb(vector<string> &a, int i, int j) {
    char c = a[i][j];
    return !('0' <= c && c <= '9' || c == '.');
}

void zero(int **a, int y, int x) {
    int xx = x;
    while (inrange(y, xx) && a[y][xx] != 0) {
        a[y][xx] = 0;
        xx--;
    }
    xx = x + 1;
    while (inrange(y, xx) && a[y][xx] != 0) {
        a[y][xx] = 0;
        xx++;
    }
}

void part1(vector<string> &input) {
    ll ans = 0;
    h = input.size();
    w = input[0].size();
    int **a = new int*[h];
    for (int i = 0; i < h; i++) {
        a[i] = new int[w];
        for (int j = 0; j < w; j++) {
            a[i][j] = 0;
        }
    }
    for (int i = 0; i < h; i++) {
        bool has = false;
        int num = 0;
        int beg = 0;
        for (int j = 0; j < w; j++) {
            char c = input[i][j];
            bool isdig = '0' <= c && c <= '9';
            if (isdig) {
                num = 10*num + c - '0';
                if (!has) {
                    has = true;
                    beg = j;
                }
            } else {
                if (has) {
                    has = false;
                    for (int k = beg; k < j; k++) {
                        a[i][k] = num;
                    }
                    num = 0;
                    beg = 0;
                }
            }
        }
        if (has) {
            for (int k = beg; k < w; k++) {
                a[i][k] = num;
            }
        }
    }

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (!issymb(input, i, j)) {
                continue;
            }
            for (int di = -1; di <= 1; di++) {
                for (int dj = -1; dj <= 1; dj++) {
                    if (di == 0 && dj == 0) {
                        continue;
                    }

                    int y = i + di;
                    int x = j + dj;
                    if (!inrange(y, x)) {
                        continue;
                    }

                    if (a[y][x] != 0) {
                        ans += a[y][x];
                        zero(a, y, x);
                    }
                }
            }
        }
    }
    cout << ans << "\n";
}

void part2(vector<string> &input) {
    ll ans = 0;
    h = input.size();
    w = input[0].size();
    int **a = new int*[h];
    for (int i = 0; i < h; i++) {
        a[i] = new int[w];
        for (int j = 0; j < w; j++) {
            a[i][j] = 0;
        }
    }
    for (int i = 0; i < h; i++) {
        bool has = false;
        int num = 0;
        int beg = 0;
        for (int j = 0; j < w; j++) {
            char c = input[i][j];
            bool isdig = '0' <= c && c <= '9';
            if (isdig) {
                num = 10*num + c - '0';
                if (!has) {
                    has = true;
                    beg = j;
                }
            } else {
                if (has) {
                    has = false;
                    for (int k = beg; k < j; k++) {
                        a[i][k] = num;
                    }
                    num = 0;
                    beg = 0;
                }
            }
        }
        if (has) {
            for (int k = beg; k < w; k++) {
                a[i][k] = num;
            }
        }
    }

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (input[i][j] != '*') {
                continue;
            }
            int i1 = -1;
            int j1 = -1;
            int i2 = -1;
            int j2 = -1;
            bool three = false;
            for (int di = -1; di <= 1; di++) {
                for (int dj = -1; dj <= 1; dj++) {
                    if (di == 0 && dj == 0) {
                        continue;
                    }

                    int y = i + di;
                    int x = j + dj;
                    if (!inrange(y, x)) {
                        continue;
                    }

                    if (a[y][x] != 0) {
                        if (i1 == -1) {
                            i1 = y;
                            j1 = x;
                        } else if (i2 == -1) {
                            if (a[i1][j1] == a[y][x]) {
                                continue;
                            }
                            i2 = y;
                            j2 = x;
                        } else {
                            if (a[i1][j1] != a[y][x] && a[i2][j2] != a[y][x]) {
                                cout << "Three: " << a[i1][j1] << ", " << a[i2][j2] << ", " << a[y][x] << "\n";
                                three = true;
                            }
                        }
                    }
                }
            }

            if (i1 != -1 && i2 != -1 && !three) {
                ans += a[i1][j1] * a[i2][j2];
                zero(a, i1, j1);
                zero(a, i2, j2);
            }
        }
    }
    cout << ans << "\n";
}

int main() {
    vector<string> input;
    while (!cin.eof()) {
        string s;
        getline(cin, s);
        input.push_back(s);
    }
    input.resize(input.size() - 1);

#ifdef PART1
    part1(input);
#else
    part2(input);
#endif
}
