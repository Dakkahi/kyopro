#include <iostream>
#include <string>
#include <map>
#include<algorithm>
#include<cmath>
#include<queue>
#include<vector>
using namespace std;
using ll = long long;

//TSP問題
int main(){
    ll N;
    cin >> N;
    ll X[N+1], Y[N+1];
    for(ll i = 1; i <= N; i++) cin >> X[i] >> Y[i];

    double dp[(1LL << N)][N+1]; //dp[S][j]で集合Sの都市を通り，現在都市jにいるときの最短経路

    for(ll i = 0; i < (1LL << N); i++){
        for(ll j = 0; j <= N; j++){
            if(i == 1 && j == 1) dp[i][j] = 0;
            else dp[i][j] = 1e9;
        }
    }

    //遷移として，dp[S][v]はdp[S\v][u](uはSの元)にcost(v,u)を足したものの最小値となるuを選ぶ
    for(ll i = 0; i < (1LL << N); i++){ //iは集合
        ll already[N+1];
        for(ll j = 1; j <= N; j++){
            if((i & (1LL << (j-1))) != 0LL) already[j] = 1;
            else already[j] = 0; //集合Sの中にjが入っていたらalready[j] = 1
        }
        for(ll j = 1; j <= N; j++){//jは最後にいる都市
            for(ll k = 1; k <= N; k++){ //集合Sの中にあるk番目の都市から都市jまでの距離を計算していく
                if(already[j] == 1 && already[k] == 1 && j != k) dp[i][j] = min(dp[i][j], dp[i - (1LL << (j-1))][k] + sqrt((X[j]-X[k])*(X[j]-X[k]) + (Y[j]-Y[k])*(Y[j]-Y[k])));
            }
        }
    }
    double ans = 1e9;
    for(ll j = 2; j <= N; j++){
        ans = min(dp[(1LL << N)-1][j] + sqrt((X[j]-X[1])*(X[j]-X[1]) + (Y[j]-Y[1])*(Y[j]-Y[1])), ans);
    }
    cout << ans << endl;
    return 0;
    
}