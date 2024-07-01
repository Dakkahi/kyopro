#include <iostream>
#include <string>
#include <map>
#include<algorithm>
#include<cmath>
#include<queue>
using namespace std;
using ll = long long;

int main(){
    ll N, H, W, P, Q;
    cin >> N >> H >> W >> P >> Q;

    ll p, q;

    ll seat[H][W];
    for(ll i = 0; i < H; i++){
        for(ll j = 0; j < W; j++) seat[i][j] = 0;
    }

    for(ll i = 1; i <= N; i++) {
        cin >> p >> q;
        seat[p][q] = 1;
    }
    ll dist = H+W+1;
    queue<pair<ll, ll>> que;
    for(ll i = 0; i < H; i++){
        for(ll j = 0; j < W; j++){
            if(seat[i][j] != 1){
                if(abs(P-i)+abs(Q-j) < dist){
                    dist = abs(P-i)+abs(Q-j);
                    while(!que.empty()) que.pop();
                    que.push(make_pair(i,j));
                }
                else if(abs(P-i)+abs(Q-j) == dist) que.push(make_pair(i,j));
            }
        }
    }
    while(!que.empty()){
        cout << que.front().first << " " << que.front().second << endl;
        que.pop();
    }
    return 0;
}