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

    for(ll i = 1; i <= N; i++){
        for(ll j = 1; j <= i; j++) cin >> A[i][j];
    }

    ll ele = 1;

    for(ll i = 1; i <= N; i++){
        if(ele >= i) ele = A[ele][i];
        else ele = A[i][ele];
    }

    cout << ele << endl;
    return 0;
}