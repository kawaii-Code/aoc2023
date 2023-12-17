#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <cassert>
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
    unordered_map<string, pair<string, string>> m;
    string ins = input[0];

    for (int i = 2; i < input.size(); i++) {
        istringstream line(input[i]);
        string from;
        string to1;
        string to2;
        line >> from >> to1 >> to1 >> to2;
        to1 = to1.substr(1, 3);
        to2 = to2.substr(0, 3);
        m[from] = {to1, to2};
    }

    int j = 0;
    string cur = "AAA";
    while (cur != "ZZZ") {
        if (ins[j] == 'R') {
            cur = m[cur].second;
        } else if (ins[j] == 'L') {
            cur = m[cur].first;
        } else {
            cout << "'" << ins[j] << "'";
            exit(-1);
            assert(false);
        }
        j = (j + 1) % ins.size();
        ans++;
    }
    cout << ans << "\n";
}

ll gcd(ll a, ll b)
{
    if (a % b == 0) {
        return b;
    }
    if (b % a == 0) {
        return a;
    }
    if (a > b) {
        return gcd(a%b, b);
    }
    return gcd(a, b%a);
}

ll lcm(ll a, ll b) 
{ 
    return a*b / gcd(a, b); 
}

void part2(vector<string> &input) {
    ll ans = 0;
    unordered_map<string, pair<string, string>> m;
    string ins = input[0];

    for (int i = 2; i < input.size(); i++) {
        istringstream line(input[i]);
        string from;
        string to1;
        string to2;
        line >> from >> to1 >> to1 >> to2;
        to1 = to1.substr(1, 3);
        to2 = to2.substr(0, 3);
        m[from] = {to1, to2};
    }

    vector<string> b;
    for (auto [k, v] : m) {
        if (k[2] == 'A') {
            b.push_back(k);
        }
    }

    vector<ll> a;
    for (int i = 0 ;i < b.size(); i++) {
        int j = 0;
        ll sum = 0;
        string cur = b[i];
        while (cur[2] != 'Z') {
            if (ins[j] == 'R') {
                cur = m[cur].second;
            } else if (ins[j] == 'L') {
                cur = m[cur].first;
            } else {
                cout << "'" << ins[j] << "'";
                exit(-1);
                assert(false);
            }
            j = (j + 1) % ins.size();
            sum++;
        }
        a.push_back(sum);
    }

    ans = a[0];
    for (int i = 1; i < a.size(); i++) {
        ans = lcm(a[i], ans);
        cout << a[i] << " " << ans << "\n";
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
