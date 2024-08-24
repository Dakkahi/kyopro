#include <iostream>
#include <string>
#include <map>
#include<algorithm>
#include<cmath>
#include<queue>
#include<vector>
using namespace std;
using ll = long long;

int main(){
    ll N, M; 
    cin >> N >> M;
    ll A[M+1];

    ll cnt[N+1];
    for(ll i = 1; i <= N; i++) cnt[i] = M;

    for(ll i = 1; i <= M; i++) {
        cin >> A[i];
        cnt[A[i]] --;
    }

    for(ll i  =1; i <= N; i++)cout << cnt[i] << endl;

    return 0;
}