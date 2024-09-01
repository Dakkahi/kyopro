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

    ll A[N+1];
    ll sum = 0;
    for(ll i = 1; i <= N; i++) {
        cin >> A[i];
    }

    sort(A+1, A+N+1, greater<ll>());
    ll cnt = 0;
    while(A[2] != 0){
        A[1] --;
        A[2] --;
        sort(A+1, A+N+1, greater<ll>());
        cnt ++;
    }
    cout << cnt << endl;
    
    return 0;
}