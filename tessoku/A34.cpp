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
    ll N, X, Y;
    cin >> N >> X >> Y;
    ll A[N+1];
    for(ll i = 1; i <= N; i++) cin >> A[i];

    ll grundy[100001];

    for(ll i = 0; i <= 100000; i++){
        bool transit[3] = {false, false, false}; //0, 1, 2の遷移状態へ行けるかどうかの判定配列
        if(i < X) grundy[i] = 0;
        else{
            if(X <= i) transit[grundy[i - X]] = true; 
            if(Y <= i) transit[grundy[i - Y]] = true;

            if(transit[0] == false) grundy[i] = 0;
            else if(transit[1] == false) grundy[i] = 1;
            else grundy[i] = 2;
        }
    }
    ll xor_sum = 0;
    for(ll i = 1; i <= N; i++) xor_sum = xor_sum^grundy[A[i]];

    if(xor_sum != 0) cout << "First" << endl;
    else cout << "Second" << endl;
    return 0;
}