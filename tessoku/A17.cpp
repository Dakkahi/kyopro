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
    ll A[N+1], B[N+1];
    for(ll i = 2; i <= N; i++) cin >> A[i];
    for(ll i = 3; i <= N; i++) cin >> B[i];

    ll dp[N+1];
    for(ll i = 1; i <=N; i++){
        if(i == 1) dp[i] = 0;
        else if(i == 2) dp[i] = A[i];
        else{
            dp[i] = min(dp[i-1]+A[i], dp[i-2]+B[i]);
        }
    }

    vector<ll> ans;
    ll pos = N;
    while(1){
        ans.push_back(pos);
        if(pos == 1) break;
        if(dp[pos] - dp[pos-1] == A[pos]) pos -= 1;
        else pos -= 2;
    }
    cout << ans.size() << endl;
    for(ll i = ans.size()-1; i >= 0; i--){
        cout <<  ans[i] <<" ";
    }
    return 0;
}