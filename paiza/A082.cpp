#include <iostream>
#include <string>
#include <map>
#include<algorithm>
#include<cmath>
#include<queue>
#include<vector>
using namespace std;
using ll = long long;


vector<ll> G[901];
bool visited[901];

void dfs(ll pos, ll ignore){
    visited[pos] = true;
    for(ll i : G[pos]){
        if(visited[i] == false) {
            visited[i] = true;
            if(i != ignore) dfs(i, ignore);
        }
    }
}

int main(){
    ll H, W;
    cin >> H >> W;
    char s[H+2][W+2];

    ll pos1, pos2; //湖の場所記録用
    pos1 = 0;
    pos2 = 0;
    //pair<ll, ll> bury; //埋め立てた場所を記録する
    for(ll i = 0; i <= H+1; i++){
        for(ll j = 0; j <= W+1; j++) {
            if(1<= i && i <= H && 1 <= j && j <= W) cin >> s[i][j]; //(i-1)*W+jで(i,j)成分とみなす
            else s[i][j] = '.';
            if(pos1 != 0 && s[i][j] == '#') pos2 = (i-1)*W+j;
            if(pos1 == 0 && s[i][j] == '#') pos1 = (i-1)*W+j;
        }
    }
    for(ll i = 1; i <= H; i++){
        for(ll j = 1; j <= W; j++){
            if(s[i][j] == '#'){
                if(s[i-1][j] == '#') G[(i-1)*W+j].push_back((i-2)*W+j);
                if(s[i+1][j] == '#') G[(i-1)*W+j].push_back(i*W+j);
                if(s[i][j-1] == '#') G[(i-1)*W+j].push_back((i-1)*W+j-1);
                if(s[i][j+1] == '#') G[(i-1)*W+j].push_back((i-1)*W+j+1);
            }
        }
    }//連結させた
    ll cnt = 0;
    for(ll i = 1; i <= H; i++){
        for(ll j = 1; j <= W; j++){
            if(s[i][j] == '.')cnt ++;
            else{
                for(ll k = 1; k <= H; k++){
                    for(ll l = 1; l <= W; l++) visited[(k-1)*W+l] = false;
                }
                if(pos1 != (i-1)*W+j) dfs(pos1, (i-1)*W+j);
                else dfs(pos2, (i-1)*W+j);

                bool connected = true;
                for(ll k = 1; k <= H; k++){
                    for(ll l = 1; l <= W; l++){
                        if(s[k][l] == '#' && visited[(k-1)*W+l] == false){
                            connected = false;
                            break;
                        }
                    }
                }
                if(connected == true) {
                    cnt ++;
                    //cout << (i-1)*W+j << endl;
                }
            }
            }
        }
    cout << cnt << endl;
    return 0;
}