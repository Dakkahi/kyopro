#include <iostream>
#include <string>
#include <queue>
using namespace std;
using ll = long long;

int main() {
    ll H, W, N;
    cin >> H >> W >> N;
    string s[H+2];
    string stack;
    
    // Initialize the grid with borders
    for (ll i = 0; i <= H+1; i++) {
        if (i == 0 || i == H+1) {
            string p = "";
            for (ll j = 0; j <= W+1; j++) {
                p += '#';
            }
            s[i] = p;
        } else {
            cin >> stack;
            stack = '#' + stack + '#';
            s[i] = stack;
        }
    }

    string op;
    cin >> op;

    for (ll k = 0; k < op.length(); k++) {
        queue<pair<ll, ll>> Q;
        if (op[k] == 'D') {
            for (ll i = 1; i <= H; i++) {
                for (ll j = 1; j <= W; j++) {
                    if (s[i][j] == '#') Q.push(make_pair(i, j));
                }
            }
            while (!Q.empty()) {
                ll i = Q.front().first;
                ll j = Q.front().second;
                Q.pop();
                if (s[i][j+1] != '#') s[i][j+1] = '#';
                if (s[i][j-1] != '#') s[i][j-1] = '#';
                if (s[i+1][j] != '#') s[i+1][j] = '#';
                if (s[i-1][j] != '#') s[i-1][j] = '#';
            }
        } else {
            for (ll i = 1; i <= H; i++) {
                for (ll j = 1; j <= W; j++) {
                    if (s[i][j] == '.') Q.push(make_pair(i, j));
                }
            }
            while (!Q.empty()) {
                ll i = Q.front().first;
                ll j = Q.front().second;
                Q.pop();
                if (s[i][j+1] != '.') s[i][j+1] = '.';
                if (s[i][j-1] != '.') s[i][j-1] = '.';
                if (s[i+1][j] != '.') s[i+1][j] = '.';
                if (s[i-1][j] != '.') s[i-1][j] = '.';
            }
        }
    }

    for (ll i = 1; i <= H; i++) {
        for (ll j = 1; j <= W; j++) {
            cout << s[i][j];
        }
        cout << endl;
    }

    return 0;
}
