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
    ll A[N+1], B[N+1];
    for(ll i = 1; i <= N; i++){
        cin >> A[i] >> B[i];
        ll mini = 1000000;
        ll maximum = 0;
        ll C[B[i]+1];
        for(ll j = 1; j <= B[i]; j++){
            cin >> C[j];
            mini = min(C[j],mini);
            mini = min(mini, A[i] - C[j]);
            maximum = max(C[j], maximum);
        }
        cout << mini << " " <<maximum << endl;
    }
    return 0;
}