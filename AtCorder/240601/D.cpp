#include <iostream>
#include<cmath>
#include<algorithm>
using namespace std;
using ll = long long;

int main(){
    ll N, M;
    cin >> N >> M;

    ll mod = 998244353;
    ll binM[61];
    ll binN[61];

    for(ll i = 0; i <= 60; i++){
        binM[i] = 0;
        binN[i] = 0;
        if((M & (1LL << i)) != 0LL) binM[i] = 1;
        if((N & (1LL << i)) != 0LL) binN[i] = 1;
    }

    ll keta = 60;
    while(binN[keta] == 0){
        keta --;
    }


    ll ans = 0;

    ll pow = 1;
    if(N <= M){
        ll num = 0;
        for(ll i = 1; i <= keta; i++){
            if(binN[i] == 1 && binM[i] == 1){
            
            }
        }
    }

    


    
}