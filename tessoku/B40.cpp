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

    ll cnt[100]; //cnt[j]で100で割った余がjである数
    for(ll j = 0; j < 100; j++) cnt[j] = 0;

    for(ll i = 1; i <= N; i++) {
        cin >> A[i];
        cnt[(A[i]%100)] ++;
    }
    ll ans = 0;
    for(ll i = 0; i < 51; i++){
       if(i == 0 || i == 50) ans += cnt[i]*(cnt[i]-1)/2;
       else{
        ans += cnt[i]*cnt[100-i];
       }
    }
    cout << ans << endl;
    return 0;
}