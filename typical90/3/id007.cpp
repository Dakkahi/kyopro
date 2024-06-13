#include <iostream>
#include <string>
#include <map>
#include<algorithm>
#include<cmath>
#include<queue>
#include<vector>
using namespace std;
using ll = long long;

ll A[300009];

ll binary_search(ll val, ll left, ll right){
    if(right - left > 1){
    ll center = (left + right)/2;
    if(val <= A[center]){
        return binary_search(val, left, center);
    }
    else{
        return binary_search(val, center, right);
    }
}
else{
        return min(abs(A[left]-val), abs(A[right]-val));
    }

}

int main(){
    ll N, Q;
    cin >> N;
    for(ll i = 1; i <= N; i++) cin >> A[i];
    cin >> Q;
    sort(A+1, A+N+1);

    ll B[Q+1];
    for(ll i = 1; i <= Q; i++) cin >> B[i];

    for(ll i = 1; i <= Q; i++){
        ll ans = binary_search(B[i], 1, N);
        cout << ans << endl;
    }
    return 0;

}