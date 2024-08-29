#include <iostream>
#include <string>
#include <map>
#include<algorithm>
#include<cmath>
#include<stack>
#include<queue>
#include<vector>
using namespace std;
using ll = long long;

int main(){
    ll t;
    cin >> t;

    queue<string> Q;
    for(ll i = 1; i <= t; i++){
        ll q;
        cin >> q;
        if(q == 1){
            string S;
            cin >> S;
            Q.push(S);
        }
        if(q == 2){
            string head = Q.front();
            cout << head << endl;
        }
        if(q == 3) Q.pop();
    }
    return 0;
}