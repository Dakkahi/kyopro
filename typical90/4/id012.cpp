#include <iostream>
#include <string>
#include <map>
#include<algorithm>
#include<cmath>
#include<queue>
#include<vector>
using namespace std;
using ll = long long;
using ull = unsigned long long;

class UnionFind {
public:
    vector<ll> parent, rank;

    UnionFind(ll n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (ll i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }

    ll find(ll x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);  // Path compression
        }
        return parent[x];
    }

    void unite(ll x, ll y) {
        ll rootX = find(x);
        ll rootY = find(y);

        if (rootX != rootY) {
            if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
            } else if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
            } else {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
        }
    }
};

int main() {
    ll H, W, Q;
    cin >> H >> W >> Q;

    ll n = H * W;
    UnionFind uf(n + 1);
    vector<ll> A(n + 1, 0);

    for (ll i = 0; i < Q; ++i) {
        int type;
        cin >> type;
        if (type == 1) {
            ll r, c;
            cin >> r >> c;
            ll idx = (r - 1) * W + c;
            A[idx] = 1;

            if (c < W && A[idx + 1] == 1) {  // Right
                uf.unite(idx, idx + 1);
            }
            if (c > 1 && A[idx - 1] == 1) {  // Left
                uf.unite(idx, idx - 1);
            }
            if (r < H && A[idx + W] == 1) {  // Down
                uf.unite(idx, idx + W);
            }
            if (r > 1 && A[idx - W] == 1) {  // Up
                uf.unite(idx, idx - W);
            }
        } else if (type == 2) {
            ll ra, ca, rb, cb;
            cin >> ra >> ca >> rb >> cb;
            ll idx1 = (ra - 1) * W + ca;
            ll idx2 = (rb - 1) * W + cb;

            if (A[idx1] == 1 && A[idx2] == 1 && uf.find(idx1) == uf.find(idx2)) {
                cout << "Yes" << endl;
            } else {
                cout << "No" << endl;
            }
        }
    }
    return 0;
}
