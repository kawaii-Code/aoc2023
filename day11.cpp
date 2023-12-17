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

#ifndef FIRST_PART
#define FIRST_PART 1
#endif

void part1(vector<string> &input) {
    string ss[100];
    ll ans = 0;
    vector<pair<int, int>> g;

    int h = input.size() - 1;
    int w = input[0].size();
    bool **exp = new bool*[h];
    for (int i = 0; i < h; i++) {
        exp[i] = new bool[w];
        for (int j = 0; j < w; j++) {
            exp[i][j] = false;
        }
    }

    for (int i = 0; i < h; i++) {
        bool has = false;
        for (int j = 0; j < w; j++) {
            if (input[i][j] == '#') {
                has = true;
                g.push_back({i,j});
            }
        }
        if (!has) {
            for (int k = 0; k < w; k++) {
                exp[i][k] = true;
            }
        }
    }
    for (int i = 0; i < w; i++) {
        bool has = false;
        for (int j = 0; j < h; j++) {
            if (input[j][i] == '#') {
                has = true;
            }
        }
        if (!has) {
            for (int k = 0; k < h; k++) {
                exp[k][i] = true;
            }
        }
    }

    ll sz = 1000*1000;
    for (int i = 0; i < g.size(); i++) {
        int gy = g[i].first;
        int gx = g[i].second;
        for (int j = i + 1; j < g.size(); j++) {
            int oy = g[j].first;
            int ox = g[j].second;

            for (int k = min(gx, ox); k < max(gx, ox); k++) {
                if (exp[gy][k]) {
                    ans += sz - 1;
                }
            }
            for (int k = min(gy, oy); k < max(gy, oy); k++) {
                if (exp[k][gx]) {
                    ans += sz - 1;
                }
            }
            ans += abs(ox - gx) + abs(oy - gy);
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

#if FIRST_PART
    part1(input);
#else
    part2(input);
#endif
}
