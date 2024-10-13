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
    ll A[2*N+1];
    ll sum = 0;
    ll ruiseki[2*N+1];
    ruiseki[0] = 0;
    for(ll i = 1; i <= N; i++) {
        cin >> A[i];
        sum += A[i];
        A[i+N] = A[i];
    }
    for(ll i = 1; i <= 2*N; i++) ruiseki[i] = ruiseki[i-1] + A[i];
    bool flag = false;
    if(sum%10 != 0){
        cout << "No" << endl;
        return 0;
    }else{
        ll div = sum/10;
        for(ll i = 1; i <= N; i++){
            ll size = ruiseki[i];
            ll pos = upper_bound(ruiseki+i+1, ruiseki+N+i-1, div+ruiseki[i-1]) - ruiseki;
            if(ruiseki[pos-1] == div+ruiseki[i-1]){
                flag = true;
                break;
            }
        }
        if(flag == true) cout << "Yes" << endl;
        else cout << "No" << endl;
        return 0;
    }
}