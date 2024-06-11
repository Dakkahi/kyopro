#include <iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
using ll = long long;

int main(){
    ll N, K;
    cin >> N >> K;

    ll A[N+1], B[N+1];
    ll sum = 0;
    for(ll i = 1; i <= N; i++){
        cin >> A[i];
    }

    for(ll i = 1; i <= N; i++){
        cin >> B[i];
        sum += abs(A[i] - B[i]);
    }
    if(K >= sum && (K-sum)%2 == 0)cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0; 

}