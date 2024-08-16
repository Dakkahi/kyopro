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
    string S;
    cin >> S;

    ll grassA[N+1];
    ll grassB[N+1];
    for(ll i = 1; i <= N; i++) {
        grassA[i] = 1;
        grassB[i] = 1;
    }


    for(ll i = 1; i <= N-1; i++){
        if(S[i-1] == 'A') grassA[i+1] = grassA[i] + 1;
        else grassA[i+1] = 1;
    }

    for(ll i = N-1; i >= 1; i--){
        if(S[i-1] == 'B') grassB[i] = grassB[i+1] + 1;
        else grassB[i] = 1;
    }

    ll sum = 0;
    for(ll i  =1; i <= N; i++) sum += max(grassA[i], grassB[i]);
    cout << sum << endl;

    return 0;
}