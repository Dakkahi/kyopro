#include <iostream>
#include<cmath>
#include<algorithm>
using namespace std;
using ll = long long;

ll gcd(ll A, ll B){
    while(A != 0 && B != 0){
        if(A > B) A = A%B;
        else B = B%A;
    }
    if(A  == 0) return B;
    else return A;
}

ll lcm(ll A, ll B){
    ll g = gcd(A, B);
    return A*B/g; //A*B = LCM(A,B)*GDC(A,B)
}

int main(){
    ll N, K;
    cin >> N >> K;
    ll V[K+1];
    for(ll i = 0; i < K; i++) cin >> V[i];
    ll ans = N;
    //包除原理を使って考える
    for(ll i = 0; i < (1LL << K); i++){ //iを0〜2^K - 1まで回す(要素がK個あるので集合自体は2^K個作れる)
        ll cnt = 0;
        ll a = 1;
        for(ll j = 0; j < K; j++){ //jを0〜K-1まで回す
            if((i & (1LL << j)) != 0){ //iと2^jのANDが0でないならiの下からj桁目は1
                cnt ++; //要素数をカウント
                a = lcm(a,V[j]); //全要素の最小公倍数を計算
        }
      }
      if(cnt%2 == 1){ //要素数が奇数なら包除原理としては足し算となる
       ans += N/a;
      }
      else{
        ans -= N/a;
      }
    }
    cout << ans << endl;
    return 0;
}