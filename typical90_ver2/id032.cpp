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
    bool hate[N+1][N+1];
    ll A[N+1][N+1];
    for(ll i = 1; i <= N; i++){
        for(ll j = 1; j <= N; j++) {
            cin >> A[i][j];
            hate[i][j] = false;
        }
    }

    ll M;
    cin >> M;
    ll X[M+1], Y[M+1];
    for(ll i = 1; i <= M; i++) {
        cin >> X[i] >> Y[i];
        hate[X[i]][Y[i]] = true;
        hate[Y[i]][X[i]] = true;
    }


    vector<ll> vec;
    for(ll i = 1; i <= N; i++) vec.push_back(i);
    ll ans = 1LL << 30;

    do{
        bool flag = true;
        ll sum = 0;
        for(ll i = 0; i < N-1; i++){
            if(hate[vec[i]][vec[i+1]] == true) flag = false;
        }
        for(ll i = 0; i < N; i++) sum += A[vec[i]][i+1];
        if(flag == true) ans = min(ans, sum);
    }while(next_permutation(vec.begin(), vec.end()));

    if(ans == (1LL << 30)) ans = -1;
    cout << ans << endl;
    return 0;
}