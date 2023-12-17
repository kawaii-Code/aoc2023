#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

#ifndef PART2
#define PART1
#endif

int strength(string h) {
    unordered_map<char, int> cnt;
    for (int i = 0 ; i < 5; i++) {
        if (cnt.find(h[i]) == cnt.end()) {
            cnt[h[i]] = 1;
        } else {
            cnt[h[i]]++;
        }
    }

    int reps = 0;
    for (auto [key, value] : cnt) {
        reps =max(reps, value);
    }

    if (reps == 5) {
        return 10;
    }

    if (reps == 4) {
        return 9;
    }

    if (reps == 3) {
        for (auto [key, value] : cnt) {
            if (value == 2) {
                return 8;
            }
        }
        return 7;
    }

    if (reps == 2) {
        int ct = 0;
        for (auto [key, value] : cnt) {
            if (value == 2) {
                ct++;
            }
        }
        if (ct == 2) {
            return 6;
        } else {
            return 5;
        }
    }

    return 4;
}

int strengthj(string h) {
    unordered_map<char, int> cnt;
    for (int i = 0 ; i < 5; i++) {
        if (cnt.find(h[i]) == cnt.end()) {
            cnt[h[i]] = 1;
        } else {
            cnt[h[i]]++;
        }
    }
    int jc = cnt['J'];

    int reps = 0;
    for (auto [key, value] : cnt) {
        if (key != 'J') {
            reps =max(reps, value);
        }
    }

    if (reps == 5 ||
        reps == 4 && jc == 1 ||
        reps == 3 && jc == 2 ||
        reps == 2 && jc == 3 ||
        reps == 1 && jc == 4 ||
        jc == 5) {
        return 10;
    }

    if (reps == 4 ||
        reps == 3 && jc == 1 ||
        reps == 2 && jc == 2 ||
        reps == 1 && jc == 3)
    {
        return 9;
    }

    if (reps == 3) {
        if (jc == 1) {
            return 8;
        }
        for (auto [key, value] : cnt) {
            if (value == 2) {
                return 8;
            }
        }
    }

    if (reps == 2 && jc == 1) {
        int ct = 0;
        for (auto [key, value] : cnt) {
            if (value == 2) {
                ct++;
            }
        }
        if (ct ==  2) {
            return 8;
        }
    }

    if (reps == 3 ||
        reps == 2 && jc == 1 ||
        reps == 1 && jc == 2)
    {
        return 7;
    }

    if (reps == 2) {
        int ct = 0;
        for (auto [key, value] : cnt) {
            if (value == 2) {
                ct++;
            }
        }
        if (ct == 2) {
            if (jc == 1) {
                return 8;
            }
            return 6;
        }
        return 5;
    }

    if (reps == 1 && jc == 1) {
        return 5;
    }

    return 4;
}


void part1(vector<string> &input) {
    ll ans = 0;

    unordered_map<char, int> ss;
    ss['A'] = 20;
    ss['K'] = 18;
    ss['Q'] = 16;
    ss['J'] = 14;
    ss['T'] = 10;

    sort(input.begin(), input.end(), [&ss](string a, string c){
            string h1 = a.substr(0, 5);
            string h2 = c.substr(0, 5);

            int s1 = strength(h1);
            int s2 = strength(h2);
            if (s1 < s2) {
                return true;
            } else if (s1 > s2) {
                return false;
            }

            for (int i = 0; i < 5; i++)
            {
                int val1 = 0;
                if ('0' <= h1[i] && h1[i] <= '9')
                {
                    val1 = h1[i] - '0';
                }
                else
                {
                    val1 = ss[h1[i]];
                }

                int val2 = 0;
                if ('0' <= h2[i] && h2[i] <= '9')
                {
                    val2 = h2[i] - '0';
                }
                else
                {
                    val2 = ss[h2[i]];
                }

                if (val1 > val2)
                {
                    return false;
                }

                if (val1 < val2)
                {
                    return true;
                }
            }

            return false;
    });

    for (int i = 0; i < input.size(); i++)
    {
        istringstream line(input[i]);
        string s;
        ll b;
        line >> s >> b;
        cout << "s = " << "'" << s << "'" << "\n";
        ans += b * (i + 1);
    }
    cout << ans << "\n";
}

void part2(vector<string> &input) {
    ll ans = 0;

    unordered_map<char, int> ss;
    ss['A'] = 20;
    ss['K'] = 18;
    ss['Q'] = 16;
    ss['J'] = 0;
    ss['T'] = 10;

    sort(input.begin(), input.end(), [&ss](string a, string c){
            string h1 = a.substr(0, 5);
            string h2 = c.substr(0, 5);

            int s1 = strengthj(h1);
            int s2 = strengthj(h2);
            if (s1 < s2) {
                return true;
            } else if (s1 > s2) {
                return false;
            }

            for (int i = 0; i < 5; i++)
            {
                int val1 = 0;
                if ('0' <= h1[i] && h1[i] <= '9')
                {
                    val1 = h1[i] - '0';
                }
                else
                {
                    val1 = ss[h1[i]];
                }

                int val2 = 0;
                if ('0' <= h2[i] && h2[i] <= '9')
                {
                    val2 = h2[i] - '0';
                }
                else
                {
                    val2 = ss[h2[i]];
                }

                if (val1 > val2)
                {
                    return false;
                }

                if (val1 < val2)
                {
                    return true;
                }
            }

            return false;
    });

    for (int i = 0; i < input.size(); i++)
    {
        istringstream line(input[i]);
        string s;
        ll b;
        line >> s >> b;
        cout << "s = " << "'" << s << "'" << "\n";
        ans += b * (i + 1);
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
