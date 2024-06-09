#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
using namespace std;
using ll = long long;


set<ll> fm_cand;
 
// m の各桁の積を返す関数
ll product(ll m) {
	if (m == 0) return 0;
	else {
		ll ans = 1;
		while (m >= 1) {
			ans *= (m % 10);
			m /= 10;
		}
		return ans;
	}
}

void func(ll digit, ll m) {
	// m の桁数は 11 桁以下
	// 注：余った桁を 1 で埋めれば、全部 11 桁と仮定しても良い
	if (digit == 11) {
		fm_cand.insert(product(m));
		return;
	}
	
	// 次の桁を探索
	// min_value は cur の最後の桁（単調増加にするためには次の桁がそれ以上でなければならない）
	ll min_value = (m % 10);
	for (ll i = min_value; i <= 9; i++) func(digit + 1, 10 * m + i);
	
}
 
int main() {
	// f(m) の候補を列挙
	func(0, 0);
 
	// 入力
	ll N, B;
	cin >> N >> B;
 
	// m - f(m) == B になるかどうかチェック
	ll Answer = 0;
	for (ll fm : fm_cand) {
		ll m = fm + B;
		ll prod_m = product(m);
		if (m - prod_m == B && m <= N) Answer++;
	}
 
	// 出力
	cout << Answer << endl;
	return 0;
}