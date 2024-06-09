#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
using ll = long long;

int main(){
    ll N;
    cin >> N;
    ll A[N+1], B[N+1];
    for(ll i = 1; i <= N; i++) cin >> A[i];
    for(ll i = 1; i <= N; i++) cin >> B[i];

    sort(A+1, A+N+1);
    sort(B+1, B+N+1);

    ll sum = 0;
    for(ll i = 1; i <= N; i++){
        sum += abs(A[i]-B[i]);
        //cout << A[i] <<" "<< B[i] << endl;
    }
    cout << sum << endl;
    return 0;
}