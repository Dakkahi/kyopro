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
    ll A[N+1][N+1];
    ll T[N+1];
    for(ll i = 1; i <= N; i++){
        T[i] = i;
        for(ll j = 1; j <= N; j++) cin >> A[i][j];
    }

    ll Q;
    cin >> Q;
    for(ll i  =1; i <= Q; i++){
        ll q, x, y;
        cin >> q >> x >> y;
        if(q == 1){
            ll x_stack = T[x];
            ll y_stack = T[y];
            T[x] = y_stack;
            T[y] = x_stack;
        }
        if(q == 2){
            cout << A[T[x]][y] << endl;
        }
    }
    return 0;
}