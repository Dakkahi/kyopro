#include <iostream>
#include <string>
#include <map>
#include<algorithm>
#include<cmath>
#include<queue>
#include<vector>
using namespace std;
using ll = long long;

int main(){
    ll H, W, N;
    cin >> H >> W >> N;

    ll s[H+2][W+2];
    for(ll i = 0; i <= H+1; i++){
        for(ll j = 0; j <= W+1; j++) s[i][j] = 0;
    }

    for(ll i = 1; i <= N; i++){
        ll a, b, c, d;
        cin >> a >> b >> c >> d;
        s[a][b] += 1;
        s[a][d+1] -= 1;
        s[c+1][b] -= 1;
        s[c+1][d+1] += 1;
    }

    for(ll i = 1; i <= H; i++){
        for(ll j = 1; j <= W; j++){
            s[i][j] += s[i][j-1];
        }
    }

    for(ll i = 1; i <= H; i++){
        for(ll j = 1; j <= W; j++){
            s[i][j] += s[i-1][j];
        }
    }

    for(ll i = 1; i <= H; i++){
        for(ll j = 1; j <= W; j++){
            if(j%W == 0) cout << s[i][j] << endl;
            else cout << s[i][j] << " ";
        }
    }
    return 0;

}