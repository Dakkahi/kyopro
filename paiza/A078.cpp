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
    char s[H+1][W+1];
    for(ll i = 1; i <= H; i++){
        for(ll j = 1; j <= W; j++) cin >> s[i][j];
    }

    bool flag = true; //マス目が消えたかどうかの判定
    while(flag == true){
        flag = false;
        for(ll i = 1; i <= H; i++){ //このループはコマを消すループ
            for(ll j = 1; j <= W; j++){
                //コーナーケース
                if(i == 1){
                    if(j == 1 && s[i][j] == s[i+1][j] && s[i][j+1] == s[i][j]){ //左端
                        flag = true;
                        s[i][j] = '.';
                        s[i+1][j] = '.';
                        s[i][j+1] = '.';
                    }else if(j == W && s[i][j] == s[i+1][j] && s[i][j-1] == s[i][j]){ //右端
                        flag = true;
                        s[i][j] = '.';
                        s[i+1][j] = '.';
                        s[i][j-1] = '.';
                    }else{ //辺
                        if(s[i][j] == s[i+1][j] && s[i][j] == s[i][j+1] && s[i][j] == s[i][j-1]){
                            flag = true;
                            s[i][j] = '.';
                            s[i+1][j] = '.';
                            s[i][j-1] = '.';
                            s[i][j+1] = '.';
                        }
                    }
                }else if(i == H){
                    if(j == 1 && s[i][j] == s[i-1][j] && s[i][j+1] == s[i][j]){ //左端
                        flag = true;
                        s[i][j] = '.';
                        s[i-1][j] = '.';
                        s[i][j+1] = '.';
                    }else if(j == W && s[i][j] == s[i+1][j] && s[i][j-1] == s[i][j]){ //右端
                        flag = true;
                        s[i][j] = '.';
                        s[i-1][j] = '.';
                        s[i][j-1] = '.';
                    }else{//辺
                        if(s[i][j] == s[i+1][j] && s[i][j] == s[i][j+1] && s[i][j] == s[i][j-1]){
                            flag = true;
                            s[i][j] = '.';
                            s[i-1][j] = '.';
                            s[i][j-1] = '.';
                            s[i][j+1] = '.';
                        }
                    }
                }
                else if(j == 1){             
                        if(s[i][j] == s[i+1][j] && s[i][j] == s[i][j+1] && s[i][j] == s[i-1][j]){
                            flag = true;
                            s[i][j] = '.';
                            s[i-1][j] = '.';
                            s[i+1][j] = '.';
                            s[i][j+1] = '.';
                        }
                }else if(j == W){             
                        if(s[i][j] == s[i+1][j] && s[i][j] == s[i][j-1] && s[i][j] == s[i-1][j]){
                            flag = true;
                            s[i][j] = '.';
                            s[i-1][j] = '.';
                            s[i+1][j] = '.';
                            s[i][j-1] = '.';
                        }
                }
                else{
                    if(s[i][j] == s[i+1][j] && s[i][j] == s[i][j-1] && s[i][j] == s[i-1][j] && s[i][j] == s[i][j+1]){
                            flag = true;
                            s[i][j] = '.';
                            s[i-1][j] = '.';
                            s[i+1][j] = '.';
                            s[i][j-1] = '.';
                            s[i][j+1] = '.';
                        }
                }
            }
        }

        for(ll i = H; i >= 2; i--){//これはマスを落とすループ
            for(ll j = 1; j <= W; j++){
                if(s[i][j] == '.'){
                    s[i][j] = s[i-1][j];
                    s[i-1][j] = '.';
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