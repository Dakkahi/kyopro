#include <iostream>
#include <string>
#include <map>
#include<algorithm>
#include<cmath>
#include<queue>
#include<vector>
using namespace std;
using ll = long long;


//Nimの必勝法
int main(){
    ll N;
    cin >> N;
    ll A[N+1];
    for(ll i = 1; i <= N; i++) cin >> A[i];

    ll xor_sum = 0;
    for(ll i = 1; i <= N; i++){
        xor_sum = xor_sum^A[i];
        //cout << xor_sum << endl;
    }
    if(xor_sum != 0) cout << "First" << endl;
    else cout << "Second" << endl;
    return 0;
}