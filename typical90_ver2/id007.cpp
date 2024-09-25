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
    ll N;
    cin >> N;
    ll A[N+1];
    for(ll i = 1; i <= N; i++) cin >> A[i];

    sort(A+1, A+N+1);

    ll Q;
    cin >> Q;
    ll B[Q+1];
    for(ll i = 1; i <= Q; i++) cin >> B[i];

    //二分探索で探す

    ll f[Q+1];

    for(ll i = 1; i <= Q; i++){
        ll frus_min = 1e9;
        ll idx = lower_bound(A+1, A+N+1, B[i]) - A;
        if(idx == 1){ //もしどれよりも小さかったら
            frus_min = min(frus_min, abs(A[idx] - B[i]));
        }
        else if(idx == N+1){ //どれよりも大きかったら
            frus_min = min(frus_min, abs(A[idx-1] - B[i]));
        }
        else{
            frus_min = min(frus_min, abs(A[idx] - B[i]));
            frus_min = min(frus_min, abs(A[idx-1] - B[i]));
        }

        cout << frus_min << endl;
    }
    return 0;
}