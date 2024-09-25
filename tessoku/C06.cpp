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

    vector<ll> G[N+1];
    cout << N << endl;
    for(ll i = 1; i <= N; i++){
        if(i != N){
            cout << i << " " << i + 1 << endl;
        }
        else{
            cout << N << " " << 1 << endl;
        }
    }
    return 0;
}