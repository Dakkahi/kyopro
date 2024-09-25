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
    priority_queue<ll, vector<ll>, greater<ll> > Q;
    for(ll i = 1; i*i <= N; i++){
        if(N%i == 0){
            Q.push(i);
            if(i*i != N) Q.push(N/i);
        }
    }
    while(!Q.empty()){
        cout << Q.top() << endl;
        Q.pop();
    }
    return 0;
}