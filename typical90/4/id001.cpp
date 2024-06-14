#include <iostream>
#include <string>
#include <map>
#include<algorithm>
#include<cmath>
#include<queue>
#include<vector>
using namespace std;
using ll = long long;
using ull = unsigned long long;


int main(){
    ll N, L, K;
    cin >> N >> L >> K;
    ll A[N+1];
    for(ll i = 1; i <= N; i++) cin >> A[i];
    A[0] = 0;
    ll left = 0;
    ll right = L;
    ll len;
    while(right - left > 1){
    ll tmp = 0;
    ll cnt = 0;
    len = (left + right)/2;
    for(ll i = 1; i <= N; i++){
        if(A[i] - A[tmp] >= len && L - A[i] >= len){
            tmp = i;
            cnt ++;
        }
    }
    if(cnt >= K){
        left = len;
    }
    else{
        right = len;
    }
    }
    cout << left << endl;
    return 0;
}