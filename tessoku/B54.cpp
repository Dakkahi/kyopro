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
    ll N;
    cin >> N;
    ll A[N+1];
    for(ll i = 1; i <= N; i++) cin >> A[i];
    map<ll, ll> M;

    ll cnt = 0;

    for(ll i = 1; i <= N; i++){
        if(M[A[i]] == 0) M[A[i]] = 1;
        else{
            cnt += M[A[i]];
            M[A[i]] ++;
        }
    }
    cout << cnt << endl;
    return 0;
}