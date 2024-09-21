#include <iostream>
#include <string>
#include <map>
#include<algorithm>
#include<cmath>
#include<queue>
#include<vector>
#include<stack>
#include<set>
using namespace std;
using ll = long long;

int main(){
    ll N;
    cin >> N;
    ll A[N+1];
    for(ll i = 1; i <= N; i++) cin >> A[i];
    set<ll> S;

    ll numtype[N+1]; //i番目までに何種類の数があるか


    for(ll i = 1; i<= N; i++){
        S.insert(A[i]);
    }



}