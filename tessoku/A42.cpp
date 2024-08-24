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

    ll A[N+1], B[N+1];
    for(ll i = 1; i <= N; i++) cin >> A[i] >> B[i];



    //(a, b)を下限とする
    ll max_val = 0;
    for(ll a = 1; a <= 100-K; a++){
        for(ll b = 1; b <= 100-K; b++){
            ll val = 0;
            for(ll i = 1; i <= N; i++){
                if(a <= A[i] && A[i] <= a+K && b <= B[i] && B[i] <= b+K) val ++;
            }
            max_val = max(val, max_val);
        }
    }
    cout << max_val << endl;
    return 0;
}