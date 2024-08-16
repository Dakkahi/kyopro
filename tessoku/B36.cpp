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
    ll N, K;
    cin >> N >> K;
    string S;
    cin >> S;
    ll cnt_0 = 0;
    ll cnt_1 = 0;
    for(ll i = 0; i < N; i++){
        if(S[i] == '0') cnt_0 ++;
        else cnt_1 ++;
    }

    if(abs(K-cnt_1)%2 == 0)cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}