#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
using ll = long long;

int main(){
    ll N;
    cin >> N;

    ll X[N+1], Y[N+1];

    for(ll i = 1; i <= N; i++) cin >> X[i] >> Y[i];

    sort(X+1, X+N+1);
    sort(Y+1, Y+N+1);
    ll sum = 0;
    for(ll i = 1; i < N; i++){
        sum += i*X[i+1] + i*Y[i+1];
        sum -= (N-i)*X[i] + (N-i)*Y[i];
    }
    cout << sum << endl;
    return 0;
}