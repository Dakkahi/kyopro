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
    ll N, K;
    cin >> N >> K;
    ll A[N+1], B[N+1];
    priority_queue<ll> Q;
    for(ll i = 1; i <= N; i++){
        cin >> A[i] >> B[i];
        Q.push(B[i]);
        Q.push(A[i]-B[i]);
    }

    ll sum = 0;
    for(ll i = 1; i <= K; i++){
        sum += Q.top();
        Q.pop();
    }
    cout << sum << endl;
    return 0;
}