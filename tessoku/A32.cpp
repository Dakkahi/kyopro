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
    ll N, A, B;
    cin >> N >> A >> B;

    bool dp[N+1]; //先手必勝のときtrue

    for(ll i = 0; i <= N; i++){
        if(i < A)dp[i] = false;
        else{
            if(i < B) dp[i] = true;
            else{
                if(dp[i-A] == false || dp[i-B] == false) dp[i] = true;
                else dp[i] = false;
            }
        }
    }
    if(dp[N] == true) cout << "First" << endl;
    else cout << "Second" << endl;
    return 0;
}