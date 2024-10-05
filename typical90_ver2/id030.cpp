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
    ll N, K;
    cin >> N >> K;

    ll num[N+1];
    bool isPrime[N+1];
    for(ll i = 1; i <= N; i++) {
        num[i] = 0;
        isPrime[i] = true;
    }


    for(ll i = 2; i <= N; i++){
        if(isPrime[i]){
            num[i]++;
            for(ll j = 2*i; j <= N; j += i){
                isPrime[j] = false;
                num[j] ++;
            }
        }
    }
    ll cnt = 0;
    for(ll i = 2; i <= N; i++){
        if(num[i] >= K) cnt++;
        //cout << num[i] << endl;
    }

    cout << cnt << endl;
    return 0;
}