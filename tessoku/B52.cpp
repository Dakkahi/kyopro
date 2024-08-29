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
    ll N, X;
    cin >> N >> X;
    string A;
    cin >> A;
    queue<ll> Q;

    Q.push(X-1);
    A[X-1] = '@';

    while(!Q.empty()){
        ll pos = Q.front();
        Q.pop();
        if(pos-1 >= 0 && A[pos-1] == '.') {
            Q.push(pos-1);
            A[pos-1] = '@';
        }
        if(pos+1 <= N-1 && A[pos+1] == '.'){
            Q.push(pos+1);
            A[pos+1] = '@';
        }
    }
    cout << A << endl;
    return 0;
}