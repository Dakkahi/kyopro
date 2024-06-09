#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
using ll = long long;

bool isprime(ll N){
    for(ll i = 2; i*i <= N; i++){
        if(N%i == 0) return false;
    }
    return true;
}

int main(){
    ll L, R;
    cin >> L >> R;
    bool prime[R-L+2];

    for(ll i = 1; i <= R-L+1; i++) prime[i] = true;
    if(L == 1) prime[1] = false;

    //エラトステネスの篩
    for(ll i = 2; i*i <= R; i++){
        ll min_val = ((L-1)/i)*i + i; //L以上で最小のiの倍数
        for(ll j = min_val; j <= R; j += i){
            if(j == i) continue;
            prime[j-L+1] = false;
        }
    }
        
    
    ll cnt = 0;
    for(ll i = 1; i <= R-L+1; i++){
        if(prime[i] == true) cnt++;
    }
    cout << cnt << endl;
    return 0;
}