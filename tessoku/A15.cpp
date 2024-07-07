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
    cin >> N;
    ll A[N+1];
    ll B[N+1];
    for(ll i = 1; i <= N; i++) cin >> A[i];

    vector<ll> T;
    for(ll i = 1; i <= N; i++) T.push_back(A[i]);

    sort(T.begin(), T.end());
    T.erase(unique(T.begin(), T.end()), T.end());

    for(ll i = 1; i <= N; i++){
        B[i] = lower_bound(T.begin(), T.end(), A[i]) - T.begin();
        B[i] += 1;
    }

    for(ll i = 1; i <= N; i++) cout << B[i] << " ";
    return 0;
}