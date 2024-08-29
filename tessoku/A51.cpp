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
    ll Q;
    cin >> Q;
    stack<string> S;
    for(ll i = 1; i <= Q; i++){
        ll q;
        cin >> q;
        if(q == 1){
            string x;
            cin >> x;
            S.push(x);
        }
        if(q == 2){
            string head = S.top();
            cout << head << endl;
        }
        if(q == 3) S.pop();
    }

    return 0;
}