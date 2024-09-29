#include <iostream>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <cmath>
#include <stack>
#include <queue>
#include <vector>

using namespace std;
using ll = long long;

int main(){
    ll N;
    cin >> N;
    string S[N+1];
    for(ll i = 1; i <= N; i++) cin >> S[i];

    map<string, ll> M;
    for(ll i = 1; i <= N; i++){
        if(M[S[i]] == 1)continue;

        M[S[i]] = 1;
        cout << i << endl;
    }
    return 0;
}