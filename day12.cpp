#include <iostream>
#include <string>
#include <vector>
#include <cassert>
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

struct C {
    ll si, ni, cn;
    bool operator==(const C &c) const {
        return si == c.si && ni == c.ni && cn == c.cn;
    }
};

struct CHash {
    size_t operator()(const C &c) const {
        return (hash<ll>()(c.si)) ^
                (hash<ll>()(c.ni)) ^
                (hash<ll>()(c.cn));
    }
};

unordered_map<C, ll, CHash> cache;

ll cntRaw(string s, ll si, vector<int> &n, ll ni, ll cn);

ll cnt(string s, ll si, vector<int> &n, ll ni, ll cn) {
    C c = {.si = si, .ni = ni, .cn = cn};
    if (cache.find(c) != cache.end()) {
        return cache[c];
    }

    ll ans = cntRaw(s, si, n, ni, cn);
    cache[c] = ans;
    return ans;
}

ll cntRaw(string s, ll si, vector<int> &n, ll ni, ll cn) {
    int nnum = 0;
    if (ni < n.size()) {
        nnum = n[ni];
    }
    if (cn > nnum) {
        return 0;
    }

    if (si >= s.size()) {
        if (cn == nnum) {
            ni++;
        }
        if (ni >= n.size()) {
            return 1;
        } else {
            return 0;
        }
    }

    char c = s[si];
    if (c == '#') {
        ll sum = 0;
        sum += cnt(s, si+1, n, ni, cn + 1);
        return sum;
    }
    if (c == '.') {
        ll sum = 0;
        if (!(cn != 0 && cn < nnum)) {
            if (cn == nnum) {
                sum += cnt(s, si + 1, n, ni+1, 0);
            } else {
                sum += cnt(s, si+1, n, ni, 0);
            }
        }
        return sum;
    }
    if (c == '?') {
        ll sum = 0;
        if (!(cn != 0 && cn < nnum)) {
            if (cn == nnum) {
                sum += cnt(s, si + 1, n, ni+1, 0);
            } else {
                sum += cnt(s, si+1, n, ni, 0);
            }
        }

        sum += cnt(s, si+1, n, ni, cn + 1);
        return sum;
    }

    assert(false);
}

void part1(vector<string> &input) {
    ll ans = 0;
    for (int i = 0; i < input.size(); i++) {
        istringstream line(input[i]);
        string s;
        line >> s;

        vector<int> n;
        char cm;
        while (!line.eof()) {
            int i;
            line >> i;
            n.push_back(i);
            line >> cm;
        }

        ll c = cnt(s, 0, n, 0, 0);
        ans += c;
    }
    cout << ans << "\n";
}

void part2(vector<string> &input) {
    ll ans = 0;
    for (int i = 0; i < input.size(); i++) {
        istringstream line(input[i]);
        string s;
        line >> s;

        vector<int> n;
        char cm;
        while (!line.eof()) {
            int i;
            line >> i;
            n.push_back(i);
            line >> cm;
        }

        string sc = "";
        vector<int> nc;
        for (int j = 0; j < 5; j++) {
            if (j != 0) {
                sc += "?";
            }
            sc += s;
            for (int k = 0; k < n.size(); k++) {
                nc.push_back(n[k]);
            }
        }

        ll c = cnt(sc, 0, nc, 0, 0);
        ans += c;
        cache.clear();
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
