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
    ll N;
    cin >> N;
    ll A[2*N+1];
    for(ll i = 1; i <= 2*N; i++) cin >> A[i];

    ll cnt = 0;
    for(ll i = 1; i <= 2*N-2; i++){
        if(A[i] == A[i+2]) cnt++;
    }
    cout << cnt << endl;
    return 0;
}