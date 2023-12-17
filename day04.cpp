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
#define FIRST_PART 0
#endif
int cards = 10;

void part1(vector<string> input) {
    string ss[100];
    int ans = 0;
    for (int i = 0; i < input.size(); i++) {
        set<int> s;
        istringstream line(input[i]);
        line >> ss[0];

        int n;
        line >> n >> ss[1];

        for (int i = 0; i < cards; i++) {
            int j;
            line >> j;
            s.insert(j);
        }

        line >> ss[2];

        int sc = 0;
        while (!line.eof()) {
            int m;
            line >> m;
            if (s.find(m) != s.end()) {
                if (sc == 0) {
                    sc = 1;
                } else {
                    sc *= 2;
                }
            }
        }
        ans += sc;
    }
    cout << ans << "\n";
}

void part2(vector<string> input) {
    string ss[100];
    int ans = 0;

    vector<int> copies(input.size());
    for (int i = 0; i < copies.size(); i++) {
        copies[i]++;
    }
    for (int i = 0; i < input.size(); i++) {
        set<int> s;
        istringstream line(input[i]);
        line >> ss[0];

        int n;
        line >> n >> ss[1];

        for (int i = 0; i < cards; i++) {
            int j;
            line >> j;
            s.insert(j);
        }

        line >> ss[2];

        int ci = i + 1;
        while (!line.eof()) {
            int m;
            line >> m;
            if (s.find(m) != s.end()) {
                copies[ci++] += copies[i];
            }
        }
    }

    for (int i = 0; i < copies.size() - 1; i++) {
        ans += copies[i];
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
