#include <iostream>
#include <string>
#include <map>
#include<algorithm>
#include<cmath>
#include<queue>
using namespace std;
using ll = long long;

int main(){
    ll H, W;
    cin >> H >> W;

    char s[H+1][W+1];
    queue<pair<pair<ll, ll>, ll>> Q; //座標の情報と爆風の距離

    ll cnt = 0; //敵の数
    for(ll i = 1; i <= H; i++){
        for(ll j = 1; j <= W; j++) {
            cin >> s[i][j];
            if(s[i][j] == 'X') cnt++;
            else if(s[i][j] != '#' && s[i][j] != '.'){
                ll num = s[i][j] - '0';
                Q.push(make_pair(make_pair(i,j), num));
            }
        }
    }
    while(!Q.empty()){
        ll i = Q.front().first.first;
        ll j = Q.front().first.second;
        ll num = Q.front().second;
        Q.pop();

        ll dir[2] = {1, -1};
        for(ll d : dir){//横方向
            for(ll k = 1; k <= num; k++){
                if(s[i][j+k*d] == 'X'){
                    cnt --;
                    s[i][j+k*d] = '.';
                }else if(s[i][j+k*d] == '#') break;
            }
            for(ll k = 1; k <= num; k++){
                if(s[i+k*d][j] == 'X'){
                    cnt --;
                    s[i+k*d][j] = '.';
                }else if(s[i+k*d][j] == '#') break;
            }
        }
    }
    if(cnt == 0) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}