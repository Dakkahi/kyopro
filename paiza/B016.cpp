#include <iostream>
#include <string>
#include <map>
#include<algorithm>
#include<cmath>
#include<queue>
#include<vector>
using namespace std;
using ll = long long;

int main() {
    ll w, h, n, x, y;
    cin >> w >> h >> n;
    cin >> x >> y;

    char dir;
    ll m;
    for(ll i = 0; i < n; i++) {
        cin >> dir >> m;
        if (dir == 'U') y += m;
        else if (dir == 'D') y -= m;
        else if (dir == 'R') x += m;
        else if (dir == 'L') x -= m;
    }

    // 正の座標に修正
    x = (x % w + w) % w;
    y = (y % h + h) % h;

    cout << x << " " << y << endl;
    return 0;
}