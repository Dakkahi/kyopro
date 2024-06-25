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
    string S[N+1];
    for(ll i = 1; i <= N; i++) cin >> S[i];

    ll cnt = 0;
    for(ll i = 1; i <= N; i++){
        if(S[i] == "Takahashi") cnt ++;
    }

    cout << cnt << endl;
    return 0;

}