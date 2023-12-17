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

struct Range {
    ll Source;
    ll Dest;
    ll Count;
};

void part1(vector<string> &input) {
    ll ans = 0;
    istringstream sl(input[0]);

    string s;
    sl >> s;

    vector<ll> seeds;
    while (!sl.eof()) {
        ll next;
        sl >> next;
        seeds.push_back(next);
    }

    vector<vector<Range>> ranges(7);
    int jj = 1;
    for (int i = 0; i < 7; i++) {
        jj += 2;

        while (jj < input.size() && input[jj].size() > 1) {
            istringstream line(input[jj]);
            Range r;
            line >> r.Dest;
            line >> r.Source;
            line >> r.Count;
            ranges[i].push_back(r);
            jj++;
        }
    }

    ans = 2147483647;
    for (int i = 0; i < seeds.size(); i++) {
        ll cur = seeds[i];
        for (int j = 0; j < 7; j++) {
            for (int k = 0; k < ranges[j].size(); k++) {
                Range r = ranges[j][k];
                if (r.Source <= cur && cur <= r.Source + r.Count) {
                    cur = r.Dest + cur - r.Source;
                    break;
                }
            }
        }
        if (cur < ans) {
            ans = cur;
        }
    }
    cout << ans << "\n";
}

void part2(vector<string> &input) {
    ll ans = 0;
    istringstream sl(input[0]);

    string s;
    sl >> s;

    vector<ll> seeds;
    while (!sl.eof()) {
        ll next;
        sl >> next;
        seeds.push_back(next);
    }

    vector<vector<Range>> ranges(7);
    int jj = 1;
    for (int i = 0; i < 7; i++) {
        jj += 2;

        while (jj < input.size() && input[jj].size() > 1) {
            istringstream line(input[jj]);
            Range r;
            line >> r.Dest;
            line >> r.Source;
            line >> r.Count;
            ranges[i].push_back(r);
            jj++;
        }
    }

    ans = 2147483647;
    for (int i = 0; i < seeds.size(); i += 2) {
        ll curr = seeds[i];
        ll len = seeds[i + 1];
        for (int f = 0; f < len; f++) {
            ll cur = curr + f;
            for (int j = 0; j < 7; j++) {
                for (int k = 0; k < ranges[j].size(); k++) {
                    Range r = ranges[j][k];
                    if (r.Source <= cur && cur < r.Source + r.Count) {
                        cur = r.Dest + cur - r.Source;
                        break;
                    }
                }
            }
            if (cur < ans) {
                ans = cur;
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

#ifdef PART1
    part1(input);
#else
    part2(input);
#endif
}
