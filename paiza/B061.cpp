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
    ll S, N;
    cin >> S;
    cin >> N;
    ll v[N+1];
    for(ll i = 1; i <= N; i++) cin >> v[i];

    sort(v+1, v+N+1);


    vector<ll> A[(1LL << N) + 1];
    ll cnt = 0;
    for(ll i = 1; i <= (1LL << N); i++){
        ll sum = 0;
        for(ll j = 0; j < N; j++){
            if((i & (1LL << j)) != 0){
                A[i].push_back(v[j+1]);
                sum += v[j+1];
            }
        }
        if(sum >= S){
            bool flag = true;
            for(ll k : A[i]){
                if(sum - k >= S){
                    flag = false;
                    break;
                }
            }
            if(flag == true) cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}