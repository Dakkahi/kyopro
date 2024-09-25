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
    ll N, Q;
    cin >> N;
    ll C[N+1];
    ll sum[N+1];
    sum[0] = 0;
    for(ll i = 1; i <= N; i++) {
        cin >> C[i];
    }
    sort(C+1, C+N+1);
    for(ll i = 1; i <= N; i++) sum[i] = sum[i-1] + C[i];

    cin >> Q;
    for(ll i = 1; i <= Q; i++){
        ll X;
        cin >> X;
        ll idx = upper_bound(sum+1, sum+N+1, X) - sum;
        cout << idx - 1 << endl;
    }
    return 0;
}