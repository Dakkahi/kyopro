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
    ll N, P, Q;
    cin >> N >> P >> Q;
    ll A[N+1];
    for(ll i = 1; i <= N; i++) cin >> A[i];

    ll cnt = 0;
    for(ll i = 1; i <= N-4; i++){
        for(ll j = i+1; j <= N-3; j++){
            for(ll k = j+1; k <= N-2; k++){
                for(ll l = k+1; l <= N-1; l++){
                    for(ll r = l+1; r <= N; r++){
                        if(1LL*A[i]%P*A[j]%P*A[k]%P*A[l]%P*A[r]%P == Q) cnt++;
                    }
                }
            }
        }
    }
    cout << cnt << endl;
    return 0;
}