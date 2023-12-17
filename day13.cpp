#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <cassert>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

#ifndef FIRST_PART
#define FIRST_PART 0
#endif

bool is_symmetrical_hor(vector<string> &input, int row) {
    assert(row > 0);
    for (int i = 0; i < input[0].size(); i++) {
        int l = row - 1;
        int r = row;
        while (l >= 0 && r < input.size()) {
            if (input[l][i] != input[r][i]) {
                return false;
            }
            l--;
            r++;
        }
    }
    return true;
}

bool is_symmetrical_ver(vector<string> &input, int col) {
    int l = col - 1;
    int r = col;
    while (l >= 0 && r < input[0].size()) {
        for (int i = 0; i < input.size(); i++) {
            if (input[i][l] != input[i][r]) {
                return false;
            }
        }
        l--;
        r++;
    }
    return true;
}

template <typename T>
std::ostream &operator<<(std::ostream &stream, std::vector<T> v) {
    if (v.size() == 0) {
        stream << "[]";
        return stream;
    }

    stream << "[";
    int i;
    for (i = 0; i < v.size() - 1; i++) {
        stream << v[i] << ", ";
    }
    stream << v[i] << "]";
    return stream;
}

void part2(vector<string> &input) {
    string ss[100];
    ull ans = 0;
    auto i = input.begin();
    while (i < input.end()) {
        auto b = i;
        while ((*i).size() >= 2) {
            i++;
        }
        vector<string> p {b, i};

        int init = 0;
        bool hor = false;
        for (int i = 1; i < p.size(); i++) {
            if (is_symmetrical_hor(p, i)) {
                init = i;
                hor = true;
                goto Test;
            }
        }
        for (int i = 1; i < p[0].size(); i++) {
            if (is_symmetrical_ver(p, i)) {
                init = i;
                hor = false;
                goto Test;
            }
        }
Test:

        int ii = 0;
        int j = 0;
        while (ii < p.size()) {
            p[ii][j] = p[ii][j] == '#' ? '.' : '#';

            for (int i = 1; i < p.size(); i++) {
                if (hor && init == i) {
                    continue;
                }
                if (is_symmetrical_hor(p, i)) {
                    cout << i << "hor " << ii << " " << j << "\n";
                    ans += 100 * i;
                    goto Out;
                }
            }
            for (int i = 1; i < p[0].size(); i++) {
                if (!hor && init == i) {
                    continue;
                }
                if (is_symmetrical_ver(p, i)) {
                    if (i == init) {
                        continue;
                    }
                    cout << i << " ver " << ii << " " << j << "\n";
                    ans += i;
                    goto Out;
                }
            }

            p[ii][j] = p[ii][j] == '#' ? '.' : '#';
            j++;
            if (j >= p[0].size()) {
                j = 0;
                ii++;
            }
        }
Out:
        i++;
    }
    cout << ans + 1 << "\n";
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
