#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
using ll = long long;

int main(){
    ll N;
    cin >> N;

    ll A[N+1];
    for(ll i = 1; i <= N; i++) cin >> A[i];
    sort(A+1, A+N+1);

    ll sum = 0;

    for(ll i = 1; i < N; i++){
        sum += i*A[i+1];
        sum -= (N-i)*A[i];
    }

    cout << sum << endl;
    return 0;

}