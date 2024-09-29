#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

class unionfind {
public:
    vector<ll> par;
    vector<ll> siz;

    void init(ll N) {
        par.resize(N + 1, -1);  // 動的にメモリを確保して初期化
        siz.resize(N + 1, 1);   // サイズも初期化
    }

    ll root(ll x) {
        while (par[x] != -1) {
            x = par[x];
        }
        return x;
    }

    void unite(ll u, ll v) {
        ll ru = root(u);
        ll rv = root(v);

        if (ru == rv) return;  // すでに同じグループなら終了

        if (siz[ru] < siz[rv]) {
            par[ru] = rv;
            siz[rv] += siz[ru];
        } else {
            par[rv] = ru;
            siz[ru] += siz[rv];
        }
    }

    bool same(ll u, ll v) {
        return root(u) == root(v);
    }
};

int main() {
    ll H, W;
    cin >> H >> W;

    // H*Wのサイズに対応するようにbool配列を動的に確保
    vector<bool> s((H + 1) * (W + 1) + 1, false);

    // Union-Find構造を初期化
    unionfind U;
    U.init((H + 1) * (W + 1));

    ll Q;
    cin >> Q;
    for (ll i = 0; i < Q; i++) {
        ll q;
        cin >> q;
        if (q == 1) {
            ll r, c;
            cin >> r >> c;
            ll pos = (r - 1) * (W + 1) + c;
            s[pos] = true;

            // 周囲のセルが有効なら、それらと連結する
            if (c < W && s[pos + 1]) U.unite(pos, pos + 1);   // 右
            if (c > 1 && s[pos - 1]) U.unite(pos, pos - 1);   // 左
            if (r < H && s[pos + W + 1]) U.unite(pos, pos + W + 1);  // 下
            if (r > 1 && s[pos - W - 1]) U.unite(pos, pos - W - 1);  // 上
        } else {
            ll ra, ca, rb, cb;
            cin >> ra >> ca >> rb >> cb;
            ll pos_a = (ra - 1) * (W + 1) + ca;
            ll pos_b = (rb - 1) * (W + 1) + cb;

            if (s[pos_a] && s[pos_b]) {
                if (U.same(pos_a, pos_b)) {
                    cout << "Yes" << endl;
                } else {
                    cout << "No" << endl;
                }
            } else {
                cout << "No" << endl;
            }
        }
    }
    return 0;
}
