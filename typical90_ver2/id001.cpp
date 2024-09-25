#include <iostream>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <cmath>
#include <stack>
#include <queue>
#include <vector>

using namespace std;
using ll = long long;


int main(){
    ll N, L;
    cin >> N >> L;

    ll K;
    cin >> K;
    ll A[N+1];
    ll diff[N+1];
    diff[0] = 0;
    A[0] = 0;
    for(ll i = 1; i <= N; i++) {
        cin >> A[i];
        diff[i] = A[i] - A[i-1];
    }

    ll left = 1;
    ll right = L;
    ll ans = 0;

    while(left <= right){
        ll center = (left + right)/2;
        ll cut = 0;
        ll current_len = 0;
        for(ll i = 1; i <= N; i++){
            if(A[i] - current_len >=center && L - A[i] >= center){
                cut ++;
                current_len = A[i];
            }
        }
        if(cut >= K){
            left = center+1;
            ans = center;
        }
        else{
            right = center-1;
        }
    }
    cout << ans << endl;
    return 0;
}