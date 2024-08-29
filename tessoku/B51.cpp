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
    string T;
    cin >> T;

    stack<ll> S;
    for(ll i = 0; i < T.length(); i++){
        if(T[i] == '('){
            S.push(i+1);
        }
        if(T[i] == ')'){
            cout << S.top() << " " << i+1 << endl;
            S.pop();
        }
    }
    return 0;
}