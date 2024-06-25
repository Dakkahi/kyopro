#include <iostream>
#include <string>
#include <map>
#include<algorithm>
#include<cmath>
#include<queue>
using namespace std;
using ll = long long;

vector<char> G[50*50+1];
vector<bool> visited(50*50+1, false);
ll len = 1;

bool dfs(ll pos){
    visited[pos] = true;
    for(ll i : G[pos]){
        if(visited[i] == false){
            len ++;
            visited[i] = true;
            dfs(i);
        }
    }
}

int main(){
    ll H, W;
    cin >> H >> W;
    

    string s[H+1];
    for(ll i = 1; i <= H; i++) cin >> s[i];

    for(ll i = 1; i <= H; i++){
        for(ll j = 1; j <= 5; j++){
            if(s[i][j] == '#'){
                if(i > 1 && s[i-1][j] == '#'){
                    G[(i-1)*W+j].push_back((i-2)*W+j);
                }
                if(i < H && s[i+1][j] == '#'){
                    G[(i-1)*W+j].push_back(i*W+j);
                }
                if(j > 1 && s[i][j-1] == '#'){
                    G[(i-1)*W+j].push_back((i-1)*W+j-1);
                }
                if(j < W && s[i][j+1] == '#'){
                    G[(i-1)*W+j].push_back((i-1)*W+j+1);
                }
            }
        }
    }

    //連結成分を数える
    ll sum = 0;
    for(ll j = 1; j <= H*W+1; j++){
        ll len_stack = len;
        if(visited[j] == false){
            dfs(j);
            sum += (len-len_stack);
        }
    }

}