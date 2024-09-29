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

ll gcd(ll a, ll b){
    if(b == 0) return a;
    else return gcd(b, a%b);
}



int main(){
    ll A, B, C;
    cin >> A >> B >> C;

    ll S = gcd(A, gcd(B,C));
    cout << (A / S - 1LL) + (B / S - 1LL) + (C / S - 1LL) << endl;
	return 0;




}