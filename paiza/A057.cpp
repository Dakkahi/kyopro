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
    ll N;
    cin >> N;
    ll s[N+1][N+1];
    for(ll i = 1; i <= N; i++){
        for(ll j = 1; j <= N; j++) cin >> s[i][j];
    }
    ll cnt = 0;
    //N<=10なので全探索でも時間的に問題ない
    for(ll i = 1; i <= N-1; i++){
        for(ll j = 1; j <= N-1; j++){
            ll tmp = 0;
            ll diff = 1; //差が1で1, -1で-1
            //まずは縦方向(下向き)
            for(ll k = i+1; k <= N; k++){
                if(s[k-1][j] - s[k][j] == 1 || s[k-1][j] - s[k][j] == -1){
                    if(tmp == 0){
                        tmp ++;
                        diff = s[k-1][j] - s[k][j];
                    }
                    else{
                        if(diff != s[k-1][j] - s[k][j]) {
                            cnt = max(tmp, cnt);
                            tmp = 0;
                            break;
                        }
                        else tmp ++;
                    }
                }
                else {
                    cnt = max(tmp, cnt);
                    tmp = 0;
                    break;
                }
            }
            //横方向(右向き)
            for(ll k = j+1; k <= N; k++){
                if(s[i][k-1] - s[i][k] == 1 || s[i][k-1] - s[i][k] == -1){
                    if(tmp == 0){
                        tmp ++;
                        diff = s[i][k-1] - s[i][k];
                    }
                    else{
                        if(diff != s[i][k-1] - s[i][k]) {
                            cnt = max(tmp, cnt);
                            tmp = 0;
                            break;
                        }
                        else tmp ++;
                    }
                }
                else {
                    cnt = max(tmp, cnt);
                    tmp = 0;
                    break;
                }
            }

            //斜め向き(右下)
            if(i < N && j < N){
                for(ll k = 1; k + max(i,j) <= N; k++){
                    if(s[i+k][j+k] - s[i+k-1][j+k-1] == 1 || s[i+k][j+k] - s[i+k-1][j+k-1] == -1){
                        if(tmp == 0){
                            tmp ++;
                            diff = s[i+k][j+k] - s[i+k-1][j+k-1];
                        }
                        else{
                            if(diff != s[i+k][j+k] - s[i+k-1][j+k-1]) {
                                cnt = max(tmp, cnt);
                                tmp = 0;
                                break;
                            }
                            else tmp ++;
                        }
                    }
                    else {
                        cnt = max(tmp, cnt);
                        tmp = 0;
                        break;
                    }
                }
            }

            //斜めむき(右上)
            if(i > 1 && j < N){
                for(ll k = 1; k + max(N-i+1,j) <= N; k++){
                    if(s[i-k][j+k] - s[i-k+1][j+k-1] == 1 || s[i-k][j+k] - s[i-k+1][j+k-1] == -1){
                        if(tmp == 0){
                            tmp ++;
                            diff =  s[i-k][j+k] - s[i-k+1][j+k-1];
                        }
                        else{
                            if(diff !=  s[i-k][j+k] - s[i-k+1][j+k-1]) {
                                cnt = max(tmp, cnt);
                                tmp = 0;
                                break;
                            }
                            else tmp ++;
                        }
                    }
                    else {
                        cnt = max(tmp, cnt);
                        tmp = 0;
                        break;
                    }
                }
            }
        }
    }
    cout << cnt << endl;
    return 0;
}