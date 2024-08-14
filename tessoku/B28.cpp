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
    ll a[N+1];
    a[0] = 0;
    a[1] = 1;
    a[2] = 1;
    ll mod = 1e9+7;
    for(ll i = 3; i <= N; i++){
        a[i] = a[i-1] + a[i-2];
        a[i] %= mod;
    }
    cout << a[N] << endl;
    return 0;
}