#include <iostream>
#include <string>
#include <map>
#include<algorithm>
#include<cmath>
using namespace std;
using ll = long long;

int main(){
    ll N, P, Q;
    cin >> N >> P >> Q;
    ll A[N+1];

    ll B[N+1]; //あまりの集合
    for(ll i = 1; i <= N; i++) {
        cin >> A[i];
        B[i] = A[i]%P;
    }
    //5個選んでPで割るとQ余る組み合わせ
    ll cnt = 0;
    for(ll i = 1; i <= N-4; i++){
        for(ll j = i+1; j <= N-3; j++){
            for(ll k = j+1; k <= N-2; k++){
                for(ll l = k+1; l <= N-1; l++){
                    for(ll m = l+1; m <= N; m++){
                        ll ans = B[i]*B[j]%P;
                        ans = ans*B[k]%P;
                        ans = ans*B[l]%P;
                        ans = ans*B[m]%P;
                        if(ans == Q) cnt++;
                    }
                }
            }
        }
    }
    cout << cnt << endl;
    return 0;

}