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
    for(ll i = 1; i <= N; i++) cin >> H[i];

    ll A[N+1];
    for(ll i = 0; i <= N; i++) A[i] = 0;

    ll T[N+1];
    ll maxi = H[1];
    ll idx = 1;
    for(ll i = 1; i <= N; i++){
        if(i == 1){
            T[i] = H[i]+1;
        }
        else{
            if(H[i] >= maxi){
                T[i] = H[i]*(i+1);
            }
            else{
                for(ll j = i-1; j >= 1; j--){
                    if(H[i] <= H[j]){
                        idx = j;
                        break;
                    }
                }
                T[i] = T[idx] + (i-idx)*H[i];
            }
        }
    }
    for(ll i = 1; i <= N; i++){
        cout << T[i] << endl;
    }
    return 0;
}