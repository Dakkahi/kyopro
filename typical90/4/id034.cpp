#include <iostream>
#include <vector>
#include <algorithm>
#include<map>

using namespace std;
using ll = long long;

int main(){
    ll N, K;
    cin >> N >> K;

    ll a[N+1];
    for(ll i = 1; i <= N; i++) cin >> a[i];

    map<ll, ll> S;

    ll r = 1;
    ll cnt = 0;
    ll ans = 0;
    for(ll i = 1; i <= N; i++){
        while(r <= N){
            if(S[a[r]] == 0 && cnt == K) break;
            if(S[a[r]] == 0) cnt++;
            S[a[r]] += 1;
            r++;
        }

        ans = max(ans, r-i);
        if(S[a[i]] == 1) cnt--;
        S[a[i]] -= 1;
    }


    cout << ans << endl;
    return 0;

}