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
    ll K, X;
    cin >> N >> K >> X;
    ll A[N+1];
    for(ll i = 1; i <= N; i++) cin >> A[i];

    vector<ll> B;
    for(ll i = 1; i <= N; i++){
        B.push_back(A[i]);
        if(i == K) B.push_back(X);
    }
    for(ll i = 0; i < B.size(); i++) cout << B[i] << " ";
    return 0;
}