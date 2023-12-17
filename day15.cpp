#include <iostream>
#include <algorithm>
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
    ll sum = 0;
    for (int i = 0; i < input.size(); i++) {
        for (int j =  0; j < input[i].size(); j++) {
            if (input[i][j] == ',') {
                ans += sum;
                cout << sum << "\n";
                sum = 0;
            } else {
                unsigned char c = input[i][j];
                sum += c;
                sum *= 17;
                sum %= 256;
            }
        }
    }
    ans += sum;
    cout << ans << "\n";
}

void part2(vector<string> &input) {
    ll ans = 0;
    ll sum = 0;
    vector<vector<pair<string, int>>> m(256);
    string s = "";
    int dig = 0;
    bool op = false;
    for (int i = 0; i < input.size(); i++) {
        for (int j =  0; j < input[i].size(); j++) {
            unsigned char c = input[i][j];
            if (c == ',') {
                auto a = find_if(m[sum].begin(), m[sum].end(), [&s](const pair<string, int> &p) {
                        if (p.first == s) {
                            return true;
                        }
                        return false;
                });
                if (a != m[sum].end()) {
                    if (op) {
                        a->second = dig;
                    } else  {
                        m[sum].erase(a);
                    }
                } else if (op) {
                    m[sum].push_back({s, dig});
                }

                sum = 0;
                s = "";
                op = false;
                dig = 0;
            } else {
                if ('0' <= c && c <= '9') {
                    dig = c - '0';
                } else if (c == '=') {
                    op = true;
                } else if (c == '-') {
                    op = false;
                } else {
                    s += c;
                    sum += c;
                    sum *= 17;
                    sum %= 256;
                }
            }
        }
    }
                auto a = find_if(m[sum].begin(), m[sum].end(), [&s](const pair<string, int> &p) {
                        if (p.first == s) {
                            return true;
                        }
                        return false;
                });
                if (a != m[sum].end()) {
                    if (op) {
                        a->second = dig;
                    } else  {
                        m[sum].erase(a);
                    }
                } else if (op) {
                    m[sum].push_back({s, dig});
                }

    for (int i = 0; i < 256; i++) {
        for (int j = 0; j < m[i].size(); j++) {
            ll sum = (m[i][j].second * (j + 1) * (i + 1));
            ans += sum;
        }
    }
    ans += sum;
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
