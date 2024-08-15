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
    ll N, X, Y;
    cin >> N >> X >> Y;

    ll A[N+1];
    for(ll i = 1; i <= N; i++) cin >> A[i];
    //grundy数は00112を周期にして変わる
    ll grundy[5] = {0, 0, 1, 1, 2};
    ll xor_sum = 0;
    for(ll i = 1; i <= N; i++) xor_sum = xor_sum^(grundy[(A[i]%5)]);

    if(xor_sum != 0) cout << "First" << endl;
    else cout << "Second" << endl;
    return 0;
}