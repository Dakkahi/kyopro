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
    ll A[N+1], B[M+1], C[N+1];
    for(ll i = 1; i <= N; i++) {
        cin >> A[i];
        C[i] = 0;
    }
    for(ll i = 1; i <= M; i++) cin >> B[i];
    ll idx = 1;
    ll g = 1;
    while(g <= M){
        if(A[(idx-1)%N] >= B[g]){
            C[(idx-1)%N] += B[g];
            B[g] = 0;
            g++;
        }
        else{
            C[(idx-1)%N] += A[(idx-1)%N];
            B[g] -= A[(idx-1)%N];
        }
        idx++;
    }
    for(ll i = 1; i <= N; i++)cout << C[i] << endl;
    return 0;
}