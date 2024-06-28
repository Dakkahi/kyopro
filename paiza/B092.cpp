#include <iostream>
#include <string>
#include <map>
#include<algorithm>
#include<cmath>
#include<queue>
using namespace std;
using ll = long long;

int main(){
    ll H, W, K;
    cin >> H >> W >> K;
    string s[H];
    pair<ll, ll> pos;
    vector<pair<char, pair<ll, ll>>> G;
    for(ll i = 0; i < H; i++) {
        cin >> s[i];
        for(ll j = 0; j < W; j++){
            if(s[i][j] == 'N') pos = make_pair(i,j);
            else if(s[i][j] != '#') G.push_back(make_pair(s[i][j], make_pair(i,j)));
        }
    }
    ll mini = H*W+1;
    priority_queue<char, vector<char>, greater<char>> Q;
    ll pos_x = pos.first;
    ll pos_y = pos.second;
    //マンハッタン距離をひたすら調べる
    for(ll i = 0; i < G.size(); i++){
        ll save_x = G[i].second.first;
        ll save_y = G[i].second.second;
        ll dis = abs(save_x -pos_x) + abs(save_y - pos_y);
        if(dis < mini){
            mini = dis;
            while(!Q.empty()){
                Q.pop();
            }
            Q.push(G[i].first);
        }
        else if(dis == mini){
            Q.push(G[i].first);
        }
    }
    ll num = Q.size();
    cout << num << endl;
    for(ll i = 0; i < num; i++){
        cout << Q.top() << endl;
        Q.pop();
    }
    return 0;
}