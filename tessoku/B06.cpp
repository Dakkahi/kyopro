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

    ll sum[N+1];
    sum[0] = 0;
    for(ll i = 1; i <= N; i++){
        ll a;
        cin >> a;
        a = 2*a-1;
        sum[i] = sum[i-1] + a;
    }
    ll Q;
    cin >> Q;
    for(ll i  =1; i <= Q; i++){
        ll r,l,diff;
        cin >> l >> r;
        diff = sum[r] - sum[l-1];
        if(diff == 0) cout << "draw" << endl;
        else if(diff > 0) cout << "win" << endl;
        else cout << "lose" << endl;
    }

    return 0;
}