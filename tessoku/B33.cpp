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
    ll N, H, W;
    cin >> N >> H >> W;
    ll A[N+1], B[N+1];
    for(ll i = 1; i <= N; i++) cin >> A[i] >> B[i];

    ll xor_sum = 0;
    for(ll i = 1; i <= N; i++){
        xor_sum = xor_sum^(A[i]-1);
        xor_sum = xor_sum^(B[i]-1);
    }
    if(xor_sum != 0) cout << "First" << endl;
    else cout << "Second" << endl;
    return 0;
}