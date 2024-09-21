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

int N, T;
vector<int> G[100009];
int ans[100009];
bool visited[100009];

int DFS(int pos) {
    visited[pos] = true;
    ans[pos] = 0;
    for (int i = 0; i < G[pos].size(); i++) {
        int to = G[pos][i];
        if (visited[to] == true) continue;
        ans[pos] = max(ans[pos], DFS(to) + 1);
    }
    return ans[pos];
}

int main() {
    cin >> N >> T;
    T--;
    for (int i = 0; i < N - 1; i++) {
        int A, B;
        cin >> A >> B;
        A--; B--;
        G[A].push_back(B);
        G[B].push_back(A);
    }
    DFS(T);
    for (int i = 0; i < N; i++) {
        if (i > 0) cout << " ";
        cout << ans[i];
    }
    cout << "\n";
    return 0;
}