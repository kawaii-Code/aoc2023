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
    string ss[100];
    ll ans = 0;
    int cap = 100;
    int **a = new int*[cap];
    for (int i = 0; i < cap; i++) {
        a[i] = new int[cap];
        for (int j = 0; j < cap; j++) {
            a[i][j] = 0;
        }
    }

    for (int i = 0; i < input.size() - 1; i++) {
        istringstream line(input[i]);
        int sz = 0;
        while (!line.eof()) {
            line >> a[0][sz++];
        }

        for (int w = 1; w < sz; w++) {
            for (int k = 0; k < sz - w; k++) {
                a[w][k] = a[w - 1][k + 1] - a[w - 1][k];
            }
        }

        ll sum = 0;
        for (int w = 0; w < sz; w++) {
            sum = sum + a[w][sz - w - 1];
        }
        ans += sum;
    }
    cout << ans << "\n";
}

void part2(vector<string> &input) {
    string ss[100];
    ll ans = 0;
    int cap = 100;
    int **a = new int*[cap];
    for (int i = 0; i < cap; i++) {
        a[i] = new int[cap];
        for (int j = 0; j < cap; j++) {
            a[i][j] = 0;
        }
    }

    for (int i = 0; i < input.size() - 1; i++) {
        istringstream line(input[i]);
        int sz = 0;
        while (!line.eof()) {
            line >> a[0][sz++];
        }

        for (int w = 1; w < sz; w++) {
            for (int k = 0; k < sz - w; k++) {
                a[w][k] = a[w - 1][k + 1] - a[w - 1][k];
            }
        }

        ll sum = 0;
        for (int w = sz; w >= 0; w--) {
            sum = a[w][0] - sum;
        }
        ans += sum;
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
