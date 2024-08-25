#include <iostream>
#include <string>
#include <map>
#include<algorithm>
#include<cmath>
#include<queue>
#include<vector>
using namespace std;
using ll = long long;

vector<ll> G[1000001];
char C[1000001];
bool visited[1000001];

void dfs_color(ll pos, char color){
    visited[pos] = true;
    for(ll i : G[pos]){
        if(visited[i] == false && C[i] == color) dfs_color(i, color); //i行j列は(i-1)*W+j
    }
}

int main(){
    ll H, W;
    cin >> H >> W;
    string S[H+2];
    for(ll i = 1; i <= H; i++) {
        cin >> S[i];
        S[i] = 'Q' + S[i] + 'Q';
    }

    for(ll i = 1; i <= H; i++){
        for(ll j = 1; j <= W; j++){
            C[(i-1)*W+j] = S[i][j];
            if(i < H){
                G[(i-1)*W+j].push_back(i*W+j);
                G[i*W+j].push_back((i-1)*W+j);
            }
            if(j < W){
                G[(i-1)*W+j].push_back((i-1)*W+j+1);
                G[(i-1)*W+j+1].push_back((i-1)*W+j);
            }
        }
    }

    for(ll i = 1; i <= H*W; i++){
        visited[i] = false;
    }

    ll r_cnt = 0;
    ll g_cnt = 0;
    ll b_cnt = 0;

    for(ll i = 1; i <= H; i++){
        for(ll j = 1; j <= W; j++){
            if(visited[(i-1)*W+j] == false){
                char color = C[(i-1)*W+j];
                dfs_color((i-1)*W+j, color);
                if(color == 'R') r_cnt ++;
                if(color == 'G') g_cnt ++;
                if(color == 'B') b_cnt ++;
            }
        }
    }

    cout << r_cnt << " " << g_cnt << " " << b_cnt << endl;
    return 0;
}