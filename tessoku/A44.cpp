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
    ll A[N+1];
    ll state = 1;
    for(ll i = 1; i <= N; i++) A[i] = i;

    for(ll i = 1; i <= Q; i++){
        ll q, x, y;
        cin >> q;
        if(q == 1){
            cin >> x >> y;
            if(state == 1) A[x] = y;
            if(state == -1) A[N-x+1] = y;
        }
        if(q == 2){
            state *= (-1);
        }
        if(q == 3){
            cin >> x;
            if(state == 1) cout << A[x] << endl;
            if(state == -1) cout << A[N-x+1] << endl;
        }
    }
    return 0;
}