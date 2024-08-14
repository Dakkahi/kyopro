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
    ll N, K;
    cin >> N >> K;
    ll a[K+1];
    for(ll i = 1; i <= K; i++) cin >> a[i];
    sort(a+1, a+K+1);

    bool dp[N+1]; //trueで先手必勝

    for(ll i = 0; i <= N; i++) dp[i] = false;


    for(ll i = a[1]; i <= N; i++){
        for(ll j = 1; j <= K; j++){
            if(i >= a[j] && dp[i-a[j]] == false){
                dp[i] = true;
                break;
            }
        }
    }
    if(dp[N] == true) cout << "First" << endl;
    else cout << "Second" << endl;
    return 0;
}