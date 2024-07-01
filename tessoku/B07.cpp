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
    ll T, N;
    cin >> T;
    cin >> N;

    ll diff[T+2];
    for(ll i = 0; i <= T+1; i++) diff[i] = 0;

    for(ll i = 1; i <= N; i++){
        ll l,r;
        cin >> l >> r;
        diff[l] ++;
        diff[r]--;
    }

    ll sum[T+2];
    sum[0] = diff[0];

        for(ll i = 0; i < T; i++){
            if(i == 0) cout << sum[0] << endl;
            else{
                sum[i] = sum[i-1] + diff[i];
                cout << sum[i] << endl;
            }
    }
    return 0;
}