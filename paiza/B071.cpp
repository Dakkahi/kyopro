#include<iostream>
#include<algorithm>
#include<vector>
#include <cmath>
#include <string>
#include <cctype>
using namespace std;
using ll = long long;

int main(){
    ll N, M;
    cin >> N >> M;

    vector<ll> G[(1LL << N)+1];

    ll w[N+1];
    for(ll i = 0; i < N; i++) cin >> w[i];

    //Nが小さいのでビット全探索
    ll max = 0;
    for(ll i = 0; i < (1LL << N); i++){
        ll sum = 0;
        for(ll j = 0; j < N; j++){
            if((i & (1LL << j)) != 0LL){
                G[i].push_back(w[j]);
                sum += w[j];
            }
        }
        //ここからダンベルの組み合わせを考える
        if(sum%2 == 0 && sum != 0){
            for(ll k = 0; k < (1LL << G[i].size()); k++){
                ll half = 0;
                for(ll r = 0; r < G[i].size(); r++){
                    if((k & (1LL << r)) != 0){
                        half += G[i][r];
                    }
                    if(half == sum/2){
                        if(max < sum && sum <= M){
                            max = sum;
                        }
                        break;
                    }
                }
            }
        }
    }
    cout << max << endl;
    return 0;
}