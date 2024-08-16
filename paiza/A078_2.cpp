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
    ll H;
    cin >> H;
    ll W = 5;
    char s[H+2][W+2];

    bool delete_memo[H+1][W+1];
    for(ll i = 1; i <= H; i++){
        for(ll j = 1; j <= W; j++) {
            cin >> s[i][j];
        }
    }


    bool flag = true; //マス目が消えたかどうかの判定
    while(flag == true){
        flag = false;
        for(ll i = 1; i <= H; i++){
            for(ll j = 1; j <= W; j++) delete_memo[i][j] = false;
        }

        //バッファを加えるループ
        for(ll i = 0; i <= H+1; i++){
            for(ll j = 0; j <= W+1; j++){
                if(i == 0){
                    if(j == 0) s[0][0] = '.';
                    else s[0][j] = s[1][j];
                }
                if(i == H+1){
                    if(j == W+1) s[H+1][W+1] = '.';
                    else s[H+1][j] = s[H][j];
                }
                if(j == 0){
                    if(i == 0) s[0][0] = '.';
                    else s[i][0] = s[i][1];
                }
                if(j == W+1){
                    if(i == H+1) s[H+1][W+1] = '.';
                    else s[i][W+1] = s[i][W];
                }
            }
        }


        for(ll i = 1; i <= H; i++){ //このループは消すコマを記憶するもの
            for(ll j = 1; j <= W; j++){
                if(s[i][j] == s[i-1][j] && s[i][j] == s[i+1][j] && s[i][j] == s[i][j-1] && s[i][j] == s[i][j+1] && s[i][j] != '.'){
                    flag = true;
                    delete_memo[i][j] = true;
                    delete_memo[i-1][j] = true;
                    delete_memo[i+1][j] = true;
                    delete_memo[i][j-1] = true;
                    delete_memo[i][j+1] = true;
                }
            }
        }

        for(ll i = 1; i <= H; i++){ //このループはコマを消すもの
            for(ll j = 1; j <= W; j++){
                if(delete_memo[i][j] == true){
                    s[i][j] = '.';
                }
            }
        }

        for(ll i = H; i >= 2; i--){//これはマスを落とすループ
            for(ll j = 1; j <= W; j++){
                if(s[i][j] == '.'){
                    ll tmp = 0;
                    while(s[i+tmp][j] == '.' && i+tmp <= H){
                        s[i+tmp][j] = s[i-1+tmp][j];
                        s[i-1+tmp][j] = '.';
                        tmp++;
                    }
                }
            }
        }
        
    }
    for(ll i = 1; i <= H; i++){
        for(ll j = 1; j <= W; j++){
            if(j == W) cout << s[i][j] << endl;
            else cout << s[i][j];
        }
    }
    return 0;
}