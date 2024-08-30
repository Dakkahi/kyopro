#include <iostream>
#include <string>
#include <map>
#include<set>
#include<algorithm>
#include<cmath>
#include<stack>
#include<queue>
#include<vector>
using namespace std;
using ll = long long;

int main(){
    ll N, Q;
    cin >> N >> Q;
    string S;
    cin >> S;
    ll mod = 2147483647;

    ll hash_f[N+1]; //前から
    ll hash_b[N+1]; //後ろから
    ll pow[N+1];
    hash_f[0] = 0; 
    hash_b[0] = 0;

    for(ll i = 0; i < N; i++){
        ll x, y;
        x = S[i];
        y = S[N-i-1];
        if(i == 0){
            pow[i+1] = 100;
            hash_f[i+1] = x%mod;
            hash_b[i+1] = y%mod;
        }
        else{
            pow[i+1] = (pow[i]*100)%mod;
            hash_f[i+1] = (x + hash_f[i]*100)%mod;
            hash_b[i+1] = (y + hash_b[i]*100)%mod;
        }
    }
    for(ll i = 1; i <= Q; i++){
        ll L, R;
        cin >> L >> R;
        ll hash_LR = hash_f[R] - (hash_f[L-1]*pow[R-L+1])%mod;
        if(hash_LR < 0) hash_LR += mod;

        ll hash_RL = hash_b[N-L+1] - (hash_b[N-R]*pow[R-L+1])%mod;
        if(hash_RL < 0) hash_RL += mod;

        if(hash_LR == hash_RL) cout << "Yes" << endl;
        else cout << "No" << endl;
    }

    return 0;
}