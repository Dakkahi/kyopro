#include <iostream>
#include <string>
#include <map>
#include<set>
#include<algorithm>
#include<cmath>
#include<stack>
#include<queue>
#include<vector>
using namespace std;
using ll = long long;

int main() {
    ll Q;
    cin >> Q;
    set<ll> S;

    for (ll i = 1; i <= Q; i++) {
        ll q, x;
        cin >> q >> x;

        if (q == 1) {
            S.insert(x);
        } else if (q == 2) {
            if (S.size() == 0) {
                cout << -1 << endl;
            } else {
                auto itr = S.lower_bound(x);

                if (itr == S.end()) {
                    --itr;
                    cout << abs(*itr - x) << endl;
                } else {
                    if (itr == S.begin()) {
                        cout << abs(*itr - x) << endl;
                    } else {
                        auto itr2 = prev(itr);
                        if (abs(*itr - x) < abs(*itr2 - x)) {
                            cout << abs(*itr - x) << endl;
                        } else {
                            cout << abs(*itr2 - x) << endl;
                        }
                    }
                }
            }
        }
    }
    return 0;
}
