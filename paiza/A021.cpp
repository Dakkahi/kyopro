#include <iostream>
#include <string>
#include <map>
#include<algorithm>
#include<cmath>
#include<queue>
#include<vector>
#include<stack>
using namespace std;
using ll = long long;

vector<ll> G[10001];
bool visited[10001];
ll grid_num;
ll len_num;

void dfs(ll pos){
    visited[pos] = true;
    grid_num ++;
    len_num += 4-G[pos].size();
    for(ll i: G[pos]){
        if(visited[i] == false) dfs(i);
    }
}

int main(){
    ll H, W;
    cin >> H >> W;
    string s[H+2];
    for(ll i = 1; i <= H; i++) {
        cin >> s[i];
        s[i] = '.' + s[i] + '.';
    }
    char dot = '.';
    for(ll i = 0; i <= W; i++){
        s[0][i] = '.';
        s[H+1][i] = '.';
    }
    //グラフを連結させていく
    for(ll i = 1; i <= H; i++){
        for(ll j = 1; j <= W; j++){
            if(s[i][j] == '#'){
                if(s[i+1][j] == '#')G[(i-1)*W+j].push_back(i*W+j);
                if(s[i-1][j] == '#')G[(i-1)*W+j].push_back((i-2)*W+j);
                if(s[i][j-1] == '#')G[(i-1)*W+j].push_back((i-1)*W+j-1);
                if(s[i][j+1] == '#')G[(i-1)*W+j].push_back((i-1)*W+j+1);
            }
            visited[(i-1)*W+j] = false;
        }
    }
    priority_queue<pair<ll, ll>> Q;

    for(ll i = 1; i <= H; i++){
        for(ll j = 1; j <= W; j++)
        if(visited[(i-1)*W+j] == false && s[i][j] == '#'){
            grid_num = 0; //面積
            len_num = 0; //海岸線の長さ
            dfs((i-1)*W+j);
            Q.push(make_pair(grid_num, len_num));
        }
    }

    while(!Q.empty()){
        pair<ll, ll> head = Q.top();
        Q.pop();
        cout << head.first << " " << head.second << endl;
    }
    return 0;
}