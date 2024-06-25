#include <iostream>
#include <deque>
#include <stack>
using namespace std;
using ll = long long;

int main() {
    ll N, M, K;
    cin >> N >> M >> K;

    deque<ll> Q;
    stack<ll> q;
    deque<ll> stock;

    for (ll i = 1; i <= N; i++) Q.push_back(i);

    for (ll i = 0; i < K; i++) {
        while (!Q.empty()) {
            ll head;
            if (i == 0) {
                head = Q.front();
                Q.pop_front();
            } else {
                head = Q.back();
                Q.pop_back();
            }
            stock.push_back(head);
        }

        while (!stock.empty()) {
            if (stock.size() % M != 0) {
                ll count = stock.size() % M;
                for (ll k = 0; k < count; k++) {
                    ll top = stock.back();
                    q.push(top);
                    stock.pop_back();
                }
            } else {
                for (ll k = 0; k < M; k++) {
                    ll top = stock.back();
                    q.push(top);
                    stock.pop_back();
                }
            }
            while (!q.empty()) {
                ll p = q.top();
                Q.push_front(p);
                q.pop();
            }
        }
    }

    while (!Q.empty()) {
        ll ans = Q.back();
        cout << ans << endl;
        Q.pop_back();
    }

    return 0;
}
