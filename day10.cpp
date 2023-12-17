#include <iostream>
#include <queue>
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

int w;
int h;

struct Move {
    int x, y, dx, dy;
};

void part1(vector<string> &input) {
    ll ans = 0;
    w = input[0].size();
    h = input.size();

    int si, sj;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (input[i][j] == 'S') {
                si = i; sj = j;
            }
        }
    }

    bool **loop = new bool*[h];
    for (int i = 0 ;i < h; i++) {
        loop[i] = new bool[w];
        for (int j = 0; j < w; j++) {
            loop[i][j] = false;
        }
    }

    queue<pair<int, int>> q;
    char ss = input[si][sj];
    // Hardcoded for my map
    q.push({si - 1, sj});
    q.push({si + 1, sj});
    //q.push({si, sj - 1});
    //q.push({si, sj + 1});
    set<pair<int, int>> s;
    while (!q.empty()) {
        pair<int, int> cur = q.front();
        q.pop();
        if (s.find(cur) != s.end()) {
            continue;
        }
        s.insert(cur);

        int i = cur.first;
        int j = cur.second;
        if (!(0 <= i && i < h && 0 <= j && j < w)) {
            continue;
        }
        loop[i][j] = true;

        char c = input[i][j];
        if (c == '|') {
            q.push({i - 1, j});
            q.push({i + 1, j});
        }
        if (c == '-') {
            q.push({i, j - 1});
            q.push({i, j + 1});
        }
        if (c == 'L') {
            q.push({i - 1, j});
            q.push({i, j + 1});
        }
        if (c == 'J') {
            q.push({i - 1, j});
            q.push({i, j - 1});
        }
        if (c == 'F') {
            q.push({i + 1, j});
            q.push({i, j + 1});
        }
        if (c == '7') {
            q.push({i + 1, j});
            q.push({i, j - 1});
        }
    }

    for (int i = 0 ; i < h ; i++) {
    for (int j = 0 ; j < w ; j++) {
        if (loop[i][j]) {
            cout << '#';
            ans++;
        } else {
        cout << '.';
        }
    }
    cout << "\n";
    }

    cout << ans / 2 << "\n";
}

void part2(vector<string> &input) {
    ll ans = 0;
    w = input[0].size();
    h = input.size();

    int si, sj;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (input[i][j] == 'S') {
                si = i; sj = j;
            }
        }
    }

    bool **loop = new bool*[h];
    for (int i = 0 ;i < h; i++) {
        loop[i] = new bool[w];
        for (int j = 0; j < w; j++) {
            loop[i][j] = false;
        }
    }

    queue<pair<int, int>> q;
    char ss = input[si][sj];
    // Hardcoded for my map
    //q.push({si - 1, sj});
    q.push({si - 1, sj});
    q.push({si, sj + 1});
    set<pair<int, int>> s;
    while (!q.empty()) {
        pair<int, int> cur = q.front();
        q.pop();
        if (s.find(cur) != s.end()) {
            continue;
        }
        s.insert(cur);

        int i = cur.first;
        int j = cur.second;
        if (!(0 <= i && i < h && 0 <= j && j < w)) {
            continue;
        }
        loop[i][j] = true;

        char c = input[i][j];
        if (c == '|') {
            q.push({i - 1, j});
            q.push({i + 1, j});
        }
        if (c == '-') {
            q.push({i, j - 1});
            q.push({i, j + 1});
        }
        if (c == 'L') {
            q.push({i - 1, j});
            q.push({i, j + 1});
        }
        if (c == 'J') {
            q.push({i - 1, j});
            q.push({i, j - 1});
        }
        if (c == 'F') {
            q.push({i + 1, j});
            q.push({i, j + 1});
        }
        if (c == '7') {
            q.push({i + 1, j});
            q.push({i, j - 1});
        }
    }

    bool even = true;
    for (int i = 0 ; i < h ; i++) {
        for (int j = 0 ; j < w ; j++) {
            char ss = input[i][j];
            if (ss == '|' || ss == 'J' || ss == 'L') {
                even = !even;
            } else if (ss == '.' && !even) {
                ans++;
            }
        }
    }

    cout << ans - 1<< "\n"; // -1 because wtf??
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
