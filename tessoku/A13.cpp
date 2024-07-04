#include <iostream>
#include <string>
#include <map>
#include<algorithm>
#include<cmath>
#include<queue>
#include<vector>
using namespace std;
using ll = long long;

int main(){
    ll N, K;
    cin >> N >> K;

    ll A[N+1];
    ll R[N];
    for(ll i = 1; i <= N; i++) cin >> A[i];

    ll cnt = 0;

    for(ll i = 1; i <= N-1; i++){
        if(i == 1) R[i] = 1;
        else R[i] = R[i-1];
        
        while(A[R[i]+1] - A[i] <= K && R[i] < N){
            R[i] ++;
        }
    }

    ll sum = 0;
    for(ll i  =1; i <= N-1; i++){
        sum += (R[i] - i);
    }

    cout << sum << endl;

    return 0;
}