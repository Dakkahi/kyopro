#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include<string>
using namespace std;
using ll = long long;

void make_carp(ll N){
    ll p = 1;

    for(ll i = 1; i <= N; i++){
        p *= 3;
    }
    ll S[p*p+1]; //(i-1)*p + j
    for(ll i = 1; i <= p*p+1; i++) S[i] = 1;
    for(ll r = 1; r <= p/3; r++){
        for(ll i = (r-1)*p + p*p/3 + p/3; i <= (r-1)*p + p*p/3 + p/3 + p/3; i++){
            S[i] = 0;
        }
    }

    
}

int main(){
    ll N;
    cin >> N;


}