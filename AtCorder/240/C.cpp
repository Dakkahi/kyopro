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
    ll H[N+1];
    for(ll i  =1; i <= N; i++) cin >> H[i];

    ll T = 0;

    for(ll i = 1; i <= N; i++){//体力は1, 1, 3ずつ減るので周期的に5だけ減る
        ll q = H[i]/5;
        ll r = H[i]%5;

        T += q*3;
        //if(r == 0) continue;

        if(r == 1){
            T ++;
        }
        if(r == 2){
            if(T%3 == 2) T += 1;
            else T += 2;
        }
        if(r == 3){
            if(T%3 == 2) T += 1;
            else if(T%3 == 1) T += 2;
            else T += 3;
        }

        if(r == 4){
            if(T%3 == 2 || T%3 == 1) T += 2;
            else T += 3;
        }
    }

    cout << T << endl;
    
    return 0;
}