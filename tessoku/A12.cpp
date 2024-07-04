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
    for(ll i  =1; i <= N; i++) cin >> A[i];

    ll l = 1;
    ll r = 1000000000;
    ll center;
    ll sum;

    while(l < r){
        sum = 0;
        center = (r+l)/2;

        for(ll i = 1; i <= N;i++) sum += center/A[i];

        if(sum < K) l = center+1;
        else if(sum >= K) r = center;
    }

    cout << l << endl;
    return 0;
}