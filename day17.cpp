#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <unordered_set>
#include <unordered_map>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

#ifndef PART2
#define PART1
#endif

struct Move {
    int x, y, dx, dy, s;
    ll d;
};

struct MoveCompare {
    bool operator()(const Move &a, const Move &b) const {
        return a.d > b.d;
    }
};

struct MoveHash {
    size_t operator()(const Move &move) const {
        return (hash<int>()(move.x)) ^
               (hash<int>()(move.y)) ^
               (hash<int>()(move.dx)) ^
               (hash<int>()(move.dy)) ^
               (hash<int>()(move.s));
    }
};

struct MoveInfo {
    int x, y, dx, dy, s;
    static MoveInfo from_move(Move &move) {
        return (MoveInfo) {.x = move.x, .y = move.y, .dx = move.dx, .dy = move.dy, .s = move.s};
    }
    bool operator==(const MoveInfo &other) const {
        return x == other.x && y == other.y && s == other.s && dx == other.dx && dy == other.dy;
    }
};

struct MoveInfoHash {
    size_t operator()(const MoveInfo &move) const {
        return (hash<int>()(move.x)) ^
               (hash<int>()(move.y)) ^
               (hash<int>()(move.s));
    }
};

void part1(vector<string> &input) {
    ll ans = 0;
    int w = input[0].size();
    int h = input.size();

    unordered_set<MoveInfo, MoveInfoHash> mi;
    priority_queue<Move, std::vector<Move>, MoveCompare> moves;
    moves.push((Move){.x=0, .y=1, .dx=0, .dy=1, .s = 1, .d = input[1][0]-'0'});
    moves.push((Move){.x=1, .y=0, .dx=1, .dy=0, .s = 1, .d = input[0][1]-'0'});

    auto make_move = [&](Move m, int dx, int dy) {
        Move n = m;
        n.x += dx;
        n.y += dy;
        n.dx = dx;
        n.dy = dy;
        if (m.dx != 0 && dx != 0 || m.dy != 0 && dy != 0) {
            n.s++;
        } else {
            n.s = 1;
        }

        if (!(0 <= n.x && n.x < w && 0 <= n.y && n.y < h)) {
            return;
        }

        n.d = m.d + input[n.y][n.x] - '0';
        moves.push(n);
    };

    while (!moves.empty()) {
        Move c = moves.top();
        if (c.x == w-1 && c.y == h-1) {
            break;
        }
        moves.pop();

        MoveInfo info = MoveInfo::from_move(c);
        if (mi.find(info) != mi.end()) {
            continue;
        }
        mi.insert(info);

        if (c.dx != 0) {
            make_move(c, 0, 1);
            make_move(c, 0, -1);
            if (c.s != 3) {
                make_move(c, c.dx, 0);
            }
        }
        if (c.dy != 0) {
            make_move(c, 1, 0);
            make_move(c, -1, 0);
            if (c.s != 3) {
                make_move(c, 0, c.dy);
            }
        }
    }

    ans = moves.top().d;
    cout << ans << "\n";
}

void part2(vector<string> &input) {
    ll ans = 0;
    int w = input[0].size();
    int h = input.size();

    unordered_set<MoveInfo, MoveInfoHash> mi;
    priority_queue<Move, std::vector<Move>, MoveCompare> moves;
    moves.push((Move){.x=0, .y=1, .dx=0, .dy=1, .s = 1, .d = input[1][0]-'0'});
    moves.push((Move){.x=1, .y=0, .dx=1, .dy=0, .s = 1, .d = input[0][1]-'0'});

    auto make_move = [&](Move m, int dx, int dy) {
        Move n = m;
        n.x += dx;
        n.y += dy;
        if (m.dx != 0 && dx != 0 || m.dy != 0 && dy != 0) {
            n.s++;
        } else {
            n.s = 1;
        }
        n.dx = dx;
        n.dy = dy;

        if (!(0 <= n.x && n.x < w && 0 <= n.y && n.y < h)) {
            return;
        }

        n.d = m.d + input[n.y][n.x] - '0';
        moves.push(n);
    };

    while (!moves.empty()) {
        Move c = moves.top();
        if (c.x == w-1 && c.y == h-1 && c.s >= 4) {
            break;
        }
        moves.pop();

        MoveInfo info = MoveInfo::from_move(c);
        if (mi.find(info) != mi.end()) {
            continue;
        }
        mi.insert(info);

        if (c.dx != 0) {
            if (c.s >= 4) {
                make_move(c, 0, 1);
                make_move(c, 0, -1);
            }
            if (c.s < 10) {
                make_move(c, c.dx, 0);
            }
        }
        if (c.dy != 0) {
            if (c.s >= 4) {
                make_move(c, 1, 0);
                make_move(c, -1, 0);
            }
            if (c.s < 10) {
                make_move(c, 0, c.dy);
            }
        }
    }

    ans = moves.top().d;
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
