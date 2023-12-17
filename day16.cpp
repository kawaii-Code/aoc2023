#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <queue>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

#ifndef PART2
#define PART1
#endif

struct Ray {
    int x, y;
    int dx, dy;
};

int w;
int h;

ll cnt(Ray initial, vector<string> &input) {
    bool **energ = new bool*[h];
    for (int i = 0 ;i  < h; i++) {
        energ[i] = new bool[w];
        for (int j = 0; j < w; j++) {
            energ[i][j] = false;
        }
    }

    queue<Ray> rays;
    set<pair<pair<int, int>, pair<int, int>>> s;
    rays.push(initial);
    while (!rays.empty()) {
        Ray current = rays.front();
        rays.pop();

        pair<pair<int, int>, pair<int, int>> b = {{current.x, current.y}, {current.dx, current.dy}};
        if (s.find(b) != s.end()) {
            continue;
        }
        s.insert(b);


        if (current.x != -1 && current.y != -1 && current.x != w && current.y != h) {
            energ[current.y][current.x] = true;
        }

        int nx = current.x + current.dx;
        int ny = current.y + current.dy;

        if (!(0 <= nx && nx < w && 0 <= ny && ny < h)) {
            continue;
        }

        char tile = input[ny][nx];
        int ndx, ndy;
        switch (tile) {
            case '|':
                if (current.dy == 0) {
                    rays.push((Ray){.x = nx, .y = ny, .dx = 0, .dy = -1 });
                    rays.push((Ray){.x = nx, .y = ny, .dx = 0, .dy = 1 });
                } else {
                    rays.push((Ray){.x = nx, .y = ny, .dx = current.dx, .dy = current.dy });
                }
                break;
            case '.':
                rays.push((Ray){.x = nx, .y = ny, .dx = current.dx, .dy = current.dy });
                break;
            case '-':
                if (current.dx == 0) {
                    rays.push((Ray){.x = nx, .y = ny, .dx = -1, .dy = 0 });
                    rays.push((Ray){.x = nx, .y = ny, .dx = 1, .dy = 0 });
                } else {
                    rays.push((Ray){.x = nx, .y = ny, .dx = current.dx, .dy = current.dy });
                }
                break;
            case '/':
                ndx = current.dx;
                ndy = current.dy;
                if (current.dx == 1) {
                    ndx = 0;
                    ndy = -1;
                } else if (current.dy == -1) {
                    ndx = 1;
                    ndy = 0;
                }  else if (current.dx == -1) {
                    ndx = 0;
                    ndy = 1;
                } else if (current.dy == 1) {
                    ndx = -1;
                    ndy = 0;
                }
                rays.push((Ray){.x=nx,.y=ny,.dx=ndx, .dy=ndy });
                break;
            case '\\':
                ndx = current.dx;
                ndy = current.dy;
                if (current.dx == 1) {
                    ndx = 0;
                    ndy = 1;
                } else if (current.dy == -1) {
                    ndx = -1;
                    ndy = 0;
                }  else if (current.dx == -1) {
                    ndx = 0;
                    ndy = -1;
                } else if (current.dy == 1) {
                    ndx = 1;
                    ndy = 0;
                }
                rays.push((Ray){.x=nx,.y=ny,.dx=ndx, .dy=ndy });
                break;
            default:
                throw 2;
        }
    }

    ll count = 0;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (energ[i][j]) {
                count++;
            }
        }
    }
    return count;
}

void part1(vector<string> &input) {
    ll ans = 0;
    w = input[0].size();
    h = input.size();

    Ray initial { .x = -1, .y = 0, .dx = 1, .dy = 0 };
    ans = cnt(initial, input);
    cout << ans << "\n";
}

void part2(vector<string> &input) {
    ll ans = 0;
    w = input[0].size();
    h = input.size();

    queue<Ray> rays;
    set<pair<pair<int, int>, pair<int, int>>> s;

    ans = max(ans, cnt((Ray) { .x = -1, .y = 0, .dx = 1, .dy = 0 }, input));
    ans = max(ans, cnt((Ray) { .x = 0, .y = -1, .dx = 0, .dy = 1 }, input));
    ans = max(ans, cnt((Ray) { .x = w, .y = 0, .dx = -1, .dy = 0 }, input));
    ans = max(ans, cnt((Ray) { .x = w - 1, .y = -1, .dx = 0, .dy = 1 }, input));
    ans = max(ans, cnt((Ray) { .x = -1, .y = h - 1, .dx = 1, .dy = 0 }, input));
    ans = max(ans, cnt((Ray) { .x = 0, .y = h, .dx = 1, .dy = -1 }, input));
    ans = max(ans, cnt((Ray) { .x = w, .y = h - 1, .dx = -1, .dy = 0 }, input));
    ans = max(ans, cnt((Ray) { .x = w - 1, .y = h, .dx = 1, .dy = -1 }, input));

    for (int ix = 0; ix < w; ix++) {
        ans = max(ans, cnt((Ray) { .x = ix, .y = -1, .dx = 0, .dy = 1 }, input));
        ans = max(ans, cnt((Ray) { .x = ix, .y = h, .dx = 0, .dy = -1 }, input));
    }
    for (int iy = 0; iy < h; iy++) {
        ans = max(ans, cnt((Ray) { .x = -1, .y = iy, .dx = 1, .dy = 0 }, input));
        ans = max(ans, cnt((Ray) { .x = w, .y = iy, .dx = -1, .dy = 0 }, input));
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
