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
    string S[N+1];
    for(ll i = 1; i <= N; i++) cin >> S[i];

    ll cnt = 0;
    for(ll i = 1; i <= N; i++){
        for(ll j = 1; j <= N; j++){
            if(S[i][j] == 'B'){
                if(j < N-1 && S[i][j+1] == 'W'){//右に白の石があれば
                    for(ll k = j+2; k <= N; k++){
                        if(S[i][k] == 'B') break;
                        if(S[i][k] == '.') {
                            cnt++;
                            break;
                        }
                    }
                }
                if(j > 3 && S[i][j-1] == 'W'){//左に白の石があれば
                    for(ll k = j-2; k >= 1; k--){
                        if(S[i][k] == 'B') break;
                        if(S[i][k] == '.') {
                            cnt++;
                            break;
                        }
                    }
                }
                if(i < N-1 && S[i+1][j] == 'W'){//下に白の石があれば
                    for(ll k = i+2; k <= N; k++){
                        if(S[k][j] == 'B') break;
                        if(S[k][j] == '.') {
                            cnt++;
                            break;
                        }
                    }
                }
                if(i > 3 && S[i-1][j] == 'W'){//上に白の石があれば
                    for(ll k = i-2; k >= 1; k--){
                        if(S[k][j] == 'B') break;
                        if(S[k][j] == '.') {
                            cnt++;
                            break;
                        }
                    }
                }

            }
        }
    }

}