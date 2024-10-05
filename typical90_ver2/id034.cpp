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
    ll N, K;
    cin >> N >> K;

    ll a[N+1];
    for(ll i = 1; i <= N; i++) cin >> a[i];

    //尺取りアルゴリズム
    ll R[N];
    ll cnt[N];
    for(ll i = 1; i <= N-1; i++) {
        R[i] = 0;
        cnt[i] = 0;
    }

    //R[i] : スタートを1番目としたとき，どこまで行けるかを表す変数

    map<ll, ll> M;


    for(ll i = 1; i <= N-1; i++){
        if(i == 1) {
            R[i] = 1;
            M[a[i]] += 1;
        }
        else R[i] = R[i-1];

        while(M.size() <= K && R[i] < N) {
            R[i]++;
            M[a[R[i]]] += 1;
        }
        if(M.size() > K) cnt[i] = R[i] - i;
        else cnt[i] = R[i] - i + 1;
        if(M[a[i]] == 1) M.erase(a[i]);
        else M[a[i]] -= 1;
    }
    sort(cnt+1, cnt+N);
    cout << cnt[N-1] << endl;
    return 0;

}