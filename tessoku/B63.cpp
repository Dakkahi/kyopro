#include <iostream>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <cmath>
#include <stack>
#include <queue>
#include <vector>

using namespace std;
using ll = long long;

int main(){
    ll R, C;
    cin >> R >> C;
    ll sx, sy, gy, gx;
    cin >> sy >> sx;
    cin >> gy >> gx;
    vector<ll> G[R*C+1];
    char s[R+2][C+2];

    for(ll i = 1; i <= R; i++){
        for(ll j = 1; j <= C; j++) cin >> s[i][j];
    }

    for(ll i = 1; i <= R; i++){
        for(ll j = 1; j <= C; j++){
            if(s[i][j] == '.'){
                if(s[i][j-1] == '.') {
                    G[(i-1)*C+j].push_back((i-1)*C+j-1);
                    G[(i-1)*C+j-1].push_back((i-1)*C+j);
                }
                if(s[i-1][j] == '.') {
                    G[(i-1)*C+j].push_back((i-2)*C+j);
                    G[(i-1)*C+j-1].push_back((i-1)*C+j);
                }
            }
        }
    }

    queue<ll> Q;
    Q.push((sy-1)*C+sx);

}