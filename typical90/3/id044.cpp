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
    ll N, Q;
    cin >> N >> Q;
    ll A[N+1], T[Q+1], x[Q+1], y[Q+1];
    for(ll i = 1; i <= N; i++) cin >> A[i];
    for(ll i = 1; i <= Q; i++) cin >> T[i] >> x[i] >> y[i];

    ll head = 1;
    ll tail = N;

    for(ll i = 1; i <= Q; i++){
       if(T[i] == 2) {
        head = tail;
        if(tail != 1) tail -= 1;
        else tail = N;
       }
       if(T[i] == 1){
        swap(A[(head + x[i] - 2)%N + 1], A[(head + y[i] - 2)%N + 1]);
       }
       if(T[i] == 3){
        cout << A[(head + x[i] - 2)%N+1] << endl;
       }
    }
    return 0;
}