#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>

using namespace std;

void part1(vector<string> input) {
    string ss[100];
    int ans = 0;
    for (int i = 0; i < input.size(); i++) {
        istringstream line(input[i]);
        line >> ss[0];

        int n;
        line >> n >> ss[99];
        int r = 0, g = 0, b = 0;
        bool can = true;
        while (!line.eof()) {
            int a;
            line >> a >> ss[1];
            if (ss[1][0] == 'b') {
                b = a;
            }
            if (ss[1][0] == 'g') {
                g = a;
            }
            if (ss[1][0] == 'r') {
                r = a;
            }

            if (r > 12) {
                can = false;
            }
            if (g > 13) {
                can = false;
            }
            if (b > 14) {
                can = false;
            }
        }

        if (can) {
            ans += n;
        }
    }
    cout << ans << "\n";
}

void part2(vector<string> input) {
    string ss[100];
    int ans = 0;
    for (int i = 0; i < input.size(); i++) {
        istringstream line(input[i]);
        line >> ss[0];

        int n;
        line >> n >> ss[99];
        int mr = 0, mg = 0, mb = 0;
        int r = 0, g = 0, b = 0;
        bool can = true;
        while (!line.eof()) {
            int a;
            line >> a >> ss[1];
            if (ss[1][0] == 'b') {
                b = a;
            }
            if (ss[1][0] == 'g') {
                g = a;
            }
            if (ss[1][0] == 'r') {
                r = a;
            }

            if (r > mr) {
                mr = r;
            }
            if (g > mg) {
                mg = g;
            }
            if (b > mb) {
                mb = b;
            }
        }

        ans += mb*mg*mr;
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
    input.pop_back();

    part1(input);
    part2(input);
}
