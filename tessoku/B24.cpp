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
    pair<ll, ll> box[N+1];
    for(ll i = 1; i <= N; i++){
        ll y;
        cin >> box[i].first >> y;
        box[i].second = -y;
    }
    sort(box+1, box+N+1);

    ll L[N+1];
    ll dp[N+1];
    ll len = 0;

    for(ll i = 1; i <= N; i++){
        ll x = lower_bound(L+1, L+len+1, -box[i].second) - L;
        dp[i] = x;
        L[x] = -box[i].second;
        if(x > len) len ++;
    }

    cout << len << endl;
    return 0;
}