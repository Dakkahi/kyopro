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
    vector<ll> divi;
    for(ll i = 2; i*i <= N; i++){
        while(N%i == 0){
            N /= i;
            divi.push_back(i);
        }
        if(N < i) break;
    }
    if(N != 1) divi.push_back(N);

    ll num = divi.size();
    ll cnt = 0;
    while(num > 1){
        num = num/2 + num%2;
        cnt++;
    }
    cout << cnt << endl;
    return 0;
}