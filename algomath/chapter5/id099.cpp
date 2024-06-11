#include<bits/stdc++.h>
#include <ctype.h>
#include <iomanip>
using namespace std;
using ll=long long;
using ull=unsigned long long;

int N, M, A[100009], B[100009];
vector<int> G[100009];

int dp[100009];
bool visited[100009];

void dfs(int pos){
    visited[pos] = true;
    dp[pos] = 1;
    for (int i:G[pos]) {
        if(visited[i]==false) {
            dfs(i);
            dp[pos] += dp[i];
        }
    }
}

int main() {
    cin >> N;
    for(int i=1; i<=N-1; i++) {
        cin >> A[i] >> B[i];
        G[A[i]].push_back(B[i]);
        G[B[i]].push_back(A[i]);
    }

    dfs(1);

    ll ans=0;
    for (int i=2; i<=N; i++){
        ans += 1LL * dp[i] * (N-dp[i]);
    }

    cout << ans << endl;
    
	return 0;
}