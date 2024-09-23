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

struct Edge {
    int to, cap, rev;
};


class MaximumFlow {
    public:
    int size = 0;
    bool used[450];
    vector<Edge> G[409];

    void init(int n) {
        size = n;
        for (int i = 0; i < n; i++) G[i].clear();
    }

    void add_edge(int a, int b, int c) {
        int Current_Ga = G[a].size();
        int Current_Gb = G[b].size();
        G[a].push_back(Edge{b, c, Current_Gb});
        G[b].push_back(Edge{a, 0, Current_Ga});
    }

    int dfs(int pos, int goal, int F) {
        if (pos == goal) return F;
        used[pos] = true;
        for (int i = 0; i < G[pos].size(); i++) {
            if (G[pos][i].cap == 0) continue;
            if (used[G[pos][i].to]) continue;
            int flow = dfs(G[pos][i].to, goal, min(F, G[pos][i].cap));
            if (flow >= 1) {
                G[pos][i].cap -= flow;
                G[G[pos][i].to][G[pos][i].rev].cap += flow;
                return flow;
            }
        }
        return 0;
    }

    int max_flow(int s, int t) {
        int Total_Flow = 0;
        while (true) {
            for (int i = 0; i < size; i++) used[i] = false;
            int F = dfs(s, t, 1e9);
            if (F == 0) break;
            Total_Flow += F;
        }
        return Total_Flow;
    }
};


int main() {
    int n, m, ans = 0;
    cin >> n >> m;
    vector<int> p(n);
    for (int i = 0; i < n; i++) cin >> p[i];
    vector<int> a(m);
    vector<int> b(m);
    for (int i = 0; i < m; i++) cin >> a[i] >> b[i];
    MaximumFlow Z;
    Z.init(n+2);
    for (int i = 0; i < n; i++) {
        if (p[i] >= 0) {
            ans += p[i];
            Z.add_edge(0, i+1, 0);
            Z.add_edge(i+1, n+1, p[i]);
        }
        else {
            Z.add_edge(0, i+1, -p[i]);
            Z.add_edge(i+1, n+1, 0);
        }
    }
    for (int i = 0; i < m; i++) {
        Z.add_edge(b[i], a[i], 1e6);
    }
    cout << ans - Z.max_flow(0, n+1) << endl;
} 