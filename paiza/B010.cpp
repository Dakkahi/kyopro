#include <iostream>
#include <string>
#include <map>
#include<algorithm>
#include<cmath>
#include<queue>
using namespace std;
using ll = long long;

int main(){
    char T;
    ll num;
    cin >> T;
    cin >> num;
    ll N = 11;

    ll A[N+1], B[N+1];
    for(ll i = 1; i <= N; i++) cin >> A[i];
    for(ll i = 1; i <= N; i++) cin >> B[i];
    
    ll cnt = 0;
    if(T == 'A'){
        queue<ll> Q;
        sort(B+1, B+N+1);
        for(ll i = 1; i <= N; i++){
            if(A[num] < A[i] && A[i] >= 55) Q.push(i); //条件1~3を満たす選手を格納
        }
        while(!Q.empty()){
            ll p = Q.front();
            Q.pop();
            ll judge = upper_bound(B+1, B+N+1, p) - B;
            if(judge >= 11) cnt++;
        }
    }

    if(T == 'B'){
        queue<ll> Q;
        
        sort(A+1, A+N+1);
        for(ll i = 1; i <= N; i++){
            if(B[num] < B[i] && B[i] <= 55) Q.push(i); //条件1~3を満たす選手を格納
        }
        while(!Q.empty()){
            ll p = Q.front();
            Q.pop();
            ll judge = upper_bound(A+1, A+N+1, p) - A;
            if(judge <= 1) cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}