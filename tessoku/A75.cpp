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
    ll N;
    cin >> N;
    pair<ll, ll> exam[N+1]; //(締切，要時間)
    for(ll i = 1; i <= N; i++) cin >> exam[i].second >> exam[i].first;

    sort(exam+1, exam+N+1);

    ll time = 0;
    ll T_max = 1440;
    ll dp[N+1][T_max+1]; //dp[i][j]で「i問目まで解くかどうか決めた時点で時刻がjのとき，最大どれだけ解けているか」
    dp[0][0] = 0;


    for(ll i = 1; i <= N; i++){
        for(ll j = 0; j <= T_max; j++){
            if(exam[i].first < j || j < exam[i].second) dp[i][j] = dp[i-1][j]; //原理的にi問目を解けない(締切時間を過ぎている，所要時間が足りていない)
            else{
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-exam[i].second] + 1); //i-1問目の時と同じか，i-1問目の時点でj-T[i]時間であり，i問目を選択する
            }
        }
    }

    ll ans = 0;
    for(ll j = 0; j <= T_max; j++) ans = max(ans, dp[N][j]);
    cout << ans << endl;
    return 0;
}