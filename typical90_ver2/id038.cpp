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

ll gcd(ll a, ll b){ //前提として a <= b
    if(a == 0) return b;
    else return gcd(b%a, a);
}

int main(){
    ll A, B;
    cin >> A >> B;
    ll a = min(A, B);
    ll b = max(A, B);

    ll gb = b/gcd(a, b);

    ll large = 1000000000000000000LL;

    if(a > large/gb) cout << "Large" << endl;
    else cout << a*gb << endl;
    return 0;
}