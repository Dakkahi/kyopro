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
    ll N, S[4];
    cin >> N;
    cin >> S[1] >> S[2] >> S[3];

    sort(S+1, S+4, greater<ll>());

    ll mini = 9999;

    for(ll i = 0; i <= N/S[1]; i++){
        for(ll j = 0; j <= (N-S[1]*i)/S[2]; j++){
            if((N-j*S[2]-i*S[1])%S[3] == 0){
                mini = min(mini, i+j+(N-j*S[2]-i*S[1])/S[3]);
            }
        }
    }
    cout << mini << endl;
    return 0;
}