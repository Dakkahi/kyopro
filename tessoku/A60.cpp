#include <iostream>
#include <stack>
using namespace std;
using ll = long long;

int main(){
    ll N;
    cin >> N;
    ll A[N+1];
    for(ll i = 1; i <= N; i++) cin >> A[i];

    stack<pair<ll, ll> > S;

    for(ll i = 1; i <= N; i++){
        if(i == 1){
            // 最初の要素には常に -1 を出力
            cout << -1 << " ";
            S.push(make_pair(A[i], i));
        }
        else{
            // スタックのトップを確認
            while(!S.empty() && S.top().first <= A[i]){
                S.pop();  // 条件を満たす間、スタックの要素をポップ
            }

            if(S.empty()){
                // スタックが空なら -1 を出力
                cout << -1 << " ";
            }
            else{
                // スタックのトップの要素が条件を満たすなら、そのインデックスを出力
                cout << S.top().second << " ";
            }
            
            // 現在の要素をスタックに追加
            S.push(make_pair(A[i], i));
        }
    }
    cout << endl;
    return 0;
}
