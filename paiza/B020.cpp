#include <iostream>
#include <vector>
#include <string>
using namespace std;
using ll = long long;

int main() {
    ll n;
    cin >> n;
    vector<string> q(n + 1);
    cin.ignore();  // 前の cin からの残りの改行文字を無視します
    for (ll i = 1; i <= n; i++) {
        getline(cin, q[i]);  // 各行全体を読み込みます
    }

    vector<string> ans(n + 1);

    vector<string> page(n+1);


    ans[1] = "blank page";

    ll len = 6;  // "go to " の長さ
    ll p = 1;
    page[p] = "blank page";


    for (ll i = 2; i <= n; i++) {
        if (q[i].substr(0, 19) == "use the back button") {
            p --;
            ans[i] = page[p];
        } else if (q[i].substr(0, len) == "go to ") {
            ans[i] = q[i].substr(len);
            p ++;
            page[p] = q[i].substr(len);
        }
    }

    for (ll i = 1; i <= n; i++) {
        cout << ans[i] << endl;
    }

    return 0;
}
