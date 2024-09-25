#include <iostream>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <cmath>
#include <stack>
#include <queue>
#include <vector>

using namespace std;
using ll = long long;

int main(){
    ll N;
    cin >> N;

    ll P[N+1][N+1];
    ll X[N+1], Y[N+1];
    for(ll i = 1; i <= N; i++){
        for(ll j = 1; j <= N; j++){
            cin >> P[i][j];
            if(P[i][j] != 0){
                X[i] = P[i][j];
                Y[j] = P[i][j];
            }
        }
    }

    ll sum = 0;
    for(ll i = 1; i <= N-1; i++){
        for(ll j = i+1; j <= N; j++){
            if(X[i] > X[j]){
                sum ++;
            }
            if(Y[i] > Y[j]){
                sum ++;
            }
        }
    }
    cout << sum << endl;
    return 0;
}