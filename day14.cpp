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

void part1(vector<string> &input) {
    ll ans = 0;
    int w = input[0].size();
    int h = input.size();
    int *rocks = new int[w];
    for (int i = 0; i <  w; i++) {
        rocks[i] = 0;
    }

    for (int i = 0; i < input.size(); i++) {
        for (int j = 0; j < w; j++) {
            if (input[i][j] == 'O') {
                rocks[j]++;
            }
        }
    }
    
    
    ll sum = 0;
    for (int j = 0; j < w; j++) {
        int rockCount = 0;
        int bottom = h;

        for (int i = 0; i < h; i++) {
            if (input[i][j] == 'O') {
                sum += bottom - rockCount;
                rockCount++;
            } else if (input[i][j] == '#') {
                bottom = h - i - 1;
                rockCount = 0;
            }
        }
    }

    cout << sum << "\n";
}

void part2(vector<string> &input) {
    ll ans = 0;
    int w = input[0].size();
    int h = input.size();
    int *rocks = new int[w];
    for (int i = 0; i <  w; i++) {
        rocks[i] = 0;
    }

    for (int i = 0; i < input.size(); i++) {
        for (int j = 0; j < w; j++) {
            if (input[i][j] == 'O') {
                rocks[j]++;
            }
        }
    }
    
    for (ll f = 3; f < 10000; f++) {
        for (ll k = 0; k < f; k++) {
            for (int j = 0; j < w; j++) {
                for (int i = 0; i < h; i++) {
                    if (input[i][j] == 'O') {
                        int ii = i - 1;
                        while (ii >= 0 && input[ii][j] != '#' && input[ii][j] != 'O') {
                            ii--;
                        }

                        ii++;
                        input[i][j] = '.';
                        input[ii][j] = 'O';
                    }
                }
            }
            for (int i = 0; i < h; i++) {
                for (int j = 0; j < w; j++) {
                    if (input[i][j] == 'O') {
                        int jj = j - 1;
                        while (jj >= 0 && input[i][jj] != '#' && input[i][jj] != 'O') {
                            jj--;
                        }

                        jj++;
                        input[i][j] = '.';
                        input[i][jj] = 'O';
                    }
                }
            }
            for (int j = 0; j < w; j++) {
                for (int i = h - 1; i >= 0; i--) {
                    if (input[i][j] == 'O') {
                        int ii = i + 1;
                        while (ii < h && input[ii][j] != '#' && input[ii][j] != 'O') {
                            ii++;
                        }

                        ii--;
                        input[i][j] = '.';
                        input[ii][j] = 'O';
                    }
                }
            }
            for (int i = 0; i < h; i++) {
                for (int j = w - 1; j >= 0; j--) {
                    if (input[i][j] == 'O') {
                        int jj = j + 1;
                        while (jj < w && input[i][jj] != '#' && input[i][jj] != 'O') {
                            jj++;
                        }

                        jj--;
                        input[i][j] = '.';
                        input[i][jj] = 'O';
                    }
                }
            }
        }

        ll sum = 0;
        for (int j = 0; j < w; j++) {
            for (int i = 0; i < h; i++) {
                if (input[i][j] == 'O') {
                    sum += h - i;
                }
            }
        }

        cout << f << ": " << sum << "\n";
    }
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
