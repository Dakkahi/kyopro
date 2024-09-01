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
    ll A[N+1];
    for(ll i = 1; i <= N; i++) cin >> A[i];

    for(ll i = N-K+1; i <= N; i++) cout << A[i] << " ";
    for(ll i = 1; i <= N-K; i++) cout << A[i] << " ";
    return 0;
}