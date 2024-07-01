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
    ll D, N;
    cin >> D;
    cin >> N;

    ll diff[D+2];
    diff[0] = 0;
    for(ll i = 1; i <= D; i++) diff[i] = 0;

    for(ll i = 1; i <= N; i++){
        ll l, r;
        cin >> l >> r;
        diff[l] ++;
        diff[r+1] --;
    }
    ll sum[D+1];
    sum[0] = 0;
    for(ll i = 1; i <= D; i++){
        sum[i] = sum[i-1] + diff[i];
        cout << sum[i] << endl;
    }
    return 0;
}