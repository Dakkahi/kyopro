#include <iostream>
#include <string>
#include <map>
#include<algorithm>
#include<cmath>
#include<queue>
#include<vector>
using namespace std;
using ll = long long;

ll A[100001];

ll binary_search(ll l, ll r, ll X){
    while(l < r){
        ll center = (l+r)/2;
        if(A[center] < X) l = center+1;
        else r  =center-1;
    }
    if(A[l] < X) return l;
    else return l-1;
}

int main(){
    ll N;
    cin >> N;
    for(ll i = 1; i <= N; i++) cin >> A[i];
    sort(A+1, A+N+1);
    ll Q;
    cin >> Q;

    for(ll i = 1; i <= Q; i++){
        ll X;
        cin >> X;
        ll ans = binary_search(1, N, X);
        cout << ans << endl;
    }
    return 0;
}
