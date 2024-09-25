#include <iostream>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <cmath>
#include <stack>
#include <queue>
#include <vector>

using namespace std;
using ll = long long;

int main(){
    ll N;
    cin >> N;

    string ans[10000];
    bool flag[10000]; //trueで当たりの可能性がある

    for(ll i = 0; i < 9999; i++){
        ans[i] = to_string(i);
        flag[i] = true;
    }
    ll S[N+1];
    string moji[N+1];
    ll T[N+1];
    for(ll i = 1; i <= N; i++) {
        cin >> S[i] >> T[i];
        moji[i] = to_string(S[i]);
    }

    for(ll i = 1; i <= N; i++){
        if(T[i] == 1) {
            cout << S[i] << endl;
            return 0;
        }
        else{
            if(T[i] == 2){
                for(ll k = 0; k <= 9999; k++){
                    ll cnt = 0;
                    for(ll j = 0; j < 4; j++){
                        if(moji[i][j] == ans[k][j]) cnt++;
                    }
                    if(cnt != 3) flag[k] = false;
                }
            }
            if(T[i] == 3){
                for(ll k = 0; k <= 9999; k++){
                    ll cnt = 0;
                    for(ll j = 0; j < 4; j++){
                        if(moji[i][j] == ans[k][j]) cnt++;
                    }
                    if(cnt >= 3) flag[k] = false;
                }
            }
        }
    }

    queue<ll> Q;
    for(ll i = 0; i < 9999; i++){
        if(flag[i] == true) Q.push(i);
    }

    if(Q.size() == 1) cout << Q.front() << endl;
    else cout << "Can't Solve" << endl;
    return 0;
}