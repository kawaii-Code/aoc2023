#include <iostream>
#include <string>
#include <queue>
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
    int h = 1000;
    int w = 1000;
    ll ans = 0;

    bool **map = new bool*[h];
    for (int i = 0; i < h; i++) {
        map[i] = new bool[w];
        for (int j = 0; j < w; j++) {
            map[i][j] = false;
        }
    }

    int curX = 500;
    int curY = 500;
    int minX = w;
    int minY = h;
    int maxX = 0;
    int maxY = 0;
    map[curY][curX] = true;

    for (int i = 0; i < input.size(); i++) {
        istringstream line(input[i]);
        char dir;
        line >> dir;
        int count;
        line >> count;
        string color;
        line >> color;
        color = color.substr(1, 7);

        if (dir == 'R') {
            for (int x = 1; x <= count; x++) {
                map[curY][curX + x] = true;
            }
            curX += count;
        } else if (dir == 'L') {
            for (int x = 1; x <= count; x++) {
                map[curY][curX - x] = true;
            }
            curX -= count;
        } else if (dir == 'U') {
            for (int y = 1; y <= count; y++) {
                map[curY - y][curX] = true;
            }
            curY -= count;
        } else if (dir == 'D') {
            for (int y = 1; y <= count; y++) {
                map[curY + y][curX] = true;
            }
            curY += count;
        }
        minX = min(curX, minX);
        minY = min(curY, minY);
        maxX = max(curX, maxX);
        maxY = max(curY, maxY);
    }
    cout << minX <<  " " ;
    cout << minY <<  " " ;
    cout << maxX <<  " " ;
    cout << maxY <<  "\n" ;

    int sx = curX + 1;
    int sy = curY + 1;
    set<pair<int, int>> s;
    queue<pair<int, int>> q;
    q.push({sx, sy});
    while (!q.empty()) {
        pair<int, int> c = q.front();
        int cy = c.first;
        int cx = c.second;
        q.pop();
        if (map[cy][cx]) {
            continue;
        }
        if (s.find(c) != s.end()) {
            continue;
        }
        s.insert(c);

        ans++;

        q.push({cy - 1, cx});
        q.push({cy + 1, cx});
        q.push({cy, cx - 1});
        q.push({cy, cx + 1});
    }
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (map[i][j]) {
                ans++;
            }
        }
    }
    cout << ans << "\n";
}

void part2(vector<string> &input) {
    ll ans = 0;
    ll sum = 0;
    vector<pair<int, int>> p;
    ll cx = 0;
    ll cy = 0;
    for (int i = 0; i < input.size(); i++) {
        istringstream line(input[i]);
        string q;
        int num;
        string c;
        line >> q >> num >> c;
        c = c.substr(2, 6);

        ll count = 0;
        for (int i = 0; i < c.size() - 1; i++) {
            int dig;
            if ('0' <= c[i] && c[i] <= '9') {
                dig = c[i] - '0';
            } else if ('a' <= c[i] && c[i] <= 'f') {
                dig = 10 + c[i] - 'a';
            }
            count = 16 * count + dig;
        }
        char d = c[5];

        cout << "dist: " << count << "\n";
        cout << "dir: " << d << "\n";

        p.push_back({cy, cx});
        ll nx, ny;
        if (d == '0') {
            nx = cx + count;
            ny = cy;
        } else if (d == '1') {
            nx = cx;
            ny = cy - count;
        } else if (d == '2') {
            nx = cx - count;
            ny = cy;
        } else if (d == '3') {
            nx = cx;
            ny = cy + count;
        }
        sum += count;
        cx = nx;
        cy = ny;
    }

    ll n = p.size();
    for (int i = 0; i < n - 1; i++) {
        ll py = p[i].first;
        ll px = p[i].second;
        ll pny = p[i+1].first;
        ll pnx = p[i+1].second;
        ans += py * pnx - px * pny;
    }
    ans = (ans + p[n - 1].first * p[0].second - p[n-1].second * p[0].first) / 2;
    cout << ans + sum / 2 + 1 << "\n";
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
