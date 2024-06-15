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
    ll N, M;
    cin >> N >> M;
    string S[N+1];
    for(ll i = 1; i <= N; i++) cin >> S[i];
    ll mini = 1024;
    for(ll i = 0; i <= (1LL << N); i++){
        map<ll, ll> T;
        ll cnt = 0;
        for(ll j = 1; j <= N; j++){
            if((i & (1LL << (j-1))) != 0LL){
                cnt ++;
                for(ll k = 1; k <= M; k++){
                    if(S[j][k-1] == 'o') T[k] = 1;
                }
            }
        }
        for(ll r = 1; r <= M; r++){
            if(T[r] == 0) {
                cnt = 1024;
                break;
            }
        }
        mini = min(cnt, mini);
    }
    cout << mini << endl;
    return 0;
}