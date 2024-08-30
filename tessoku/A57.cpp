#include <iostream>
#include <string>
#include <map>
#include<set>
#include<algorithm>
#include<cmath>
#include<stack>
#include<queue>
#include<vector>
using namespace std;
using ll = long long;

int main(){
    ll N, Q;
    cin >> N >> Q;
    ll A[N+1];
    for(ll i = 1; i <= N; i++) cin >> A[i];

    ll dp[30][N+1]; // dp[i][j]で「穴jにいたときに2^i日後にいる場所」

    for(ll i = 0; i <= 30; i++){
        for(ll j = 1; j <= N; j++){
            if(i == 0) dp[i][j] = A[j];
            else{
                dp[i][j] = dp[i-1][dp[i-1][j]];
            }
        }
    }

    for(ll i = 1; i <= Q; i++){
        ll X, Y;
        cin >> X >> Y;
        for(ll j = 0; j <= 30; j++){
            if((Y & (1LL << j)) != 0LL){
                X = dp[j][X];
            }
        }
        cout << X << endl;
    }
}