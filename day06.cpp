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

void part1(vector<string> input) {
    string ss[100];
    ull ans = 1;

    vector<ull> t;
    istringstream l0(input[0]);
    l0 >> ss[0];
    while (!l0.eof()) {
        int t0;
        l0 >> t0;
        t.push_back(t0);
    }

    vector<ull> d;
    istringstream l1(input[1]);
    l1 >> ss[0];
    while (!l1.eof()) {
        int d0;
        l1 >> d0;
        d.push_back(d0);
    }

    for (int i = 0; i < t.size(); i++) {
        int ways = 0;
        int tt = t[i];
        int dd = d[i];
        for (int j = 0; j <= tt; j++) {
            int ddd = j * (tt - j);
            if (ddd > dd) {
                ways++;
            }
        }
        ans *= ways;
    }
    cout << ans << "\n";
}

void part2(vector<string> input) {
    string ss[100];
    ull ans = 0;

    vector<ull> t;
    istringstream l0(input[0]);
    l0 >> ss[0];
    stringstream s;
    while (!l0.eof()) {
        int t0;
        l0 >> t0;
        s << to_string(t0);
    }
    ull f;
    istringstream s2(s.str());
    s2 >> f;
    t.push_back(f);

    vector<ull> d;
    istringstream l1(input[1]);
    stringstream s3;
    l1 >> ss[0];
    while (!l1.eof()) {
        int d0;
        l1 >> d0;
        s3 << d0;
    }
    istringstream abc(s3.str());
    abc >> f;
    d.push_back(f);

    for (int i = 0; i < t.size(); i++) {
        ull tt = t[i];
        ull dd = d[i];
        for (int j = 0; j <= tt; j++) {
            ull ddd = j * (tt - j);
            if (ddd > dd) {
                ans++;
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

#if FIRST_PART
    part1(input);
#else
    part2(input);
#endif
}
