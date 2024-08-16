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
     ll A[2*N+1];
     for(ll i = 1; i <= 2*N; i++){
        cin >> A[i];
     }

     bool flag[N+1];
     for(ll i = 1; i <= N; i++) flag[i] = false;

    ll sum = 0;
     for(ll i = 1; i <= 2*N; i++){
        if(flag[A[i]] == false){
            flag[A[i]] = true;
            ll cnt = 1;
            while(A[i] != A[i+cnt]) cnt ++;
            sum = sum + cnt - 1;
        }
     }
     cout << sum << endl;
     return 0;
}