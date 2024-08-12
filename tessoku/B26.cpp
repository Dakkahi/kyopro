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

    ll num[N+1];
    for(ll i = 2; i <= N; i++) num[i] = 0;

    for(ll i = 2; i <= N; i++){
        for(ll j = i; j <= N; j+=i){
            num[j] ++;
        }
    }

    for(ll i = 2; i <= N; i++){
        if(num[i] == 1)cout << i << endl;
    }
    return 0;
}