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
    ll A[N+1];

    ll cnt[101];
    for(ll i = 1; i <= 100; i++) cnt[i] = 0;

    for(ll i = 1; i <= N; i++) {
        cin >> A[i];
        cnt[A[i]] += 1;
    }
    ll ans = 0;
    for(ll i = 1; i <= 100; i++){
        ans += cnt[i]*(cnt[i]-1)*(cnt[i]-2)/6;
    }
    cout << ans << endl;
    return 0;
}