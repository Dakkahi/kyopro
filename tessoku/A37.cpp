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
    ll N, M ,B;
    cin >> N >> M >> B;
    ll A[N+1], C[M+1];
    for(ll i = 1; i <= N; i++) cin >> A[i];
    for(ll j = 1; j <= M; j++) cin >> C[j];

    ll sum = 0;
    for(ll i = 1; i <= N; i++){
        sum += A[i]*M;
    }
    for(ll j = 1; j <= M; j++){
        sum += C[j]*N;
    }
    sum += B*M*N;
    cout << sum << endl;
    return 0;
    }