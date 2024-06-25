#include <iostream>
#include <string>
#include <map>
#include<algorithm>
#include<cmath>
#include<queue>
using namespace std;
using ll = long long;

ll pow(ll a, ll n){
    ll ans = 0;
    ll p  = a;
    for(ll i = 1; i <= n; i++){
        ans += p;
        p *= a;
    }
    return ans;
}

int main(){
    string S, T;
    cin >> S >> T;

    ll a = 0;
    ll b = 0;
    for(ll i = 0; i < S.length(); i++){
        ll s = S[S.length()-1-i]-65;
        a += s*pow(5, i);
    }


    for(ll i = 0; i < T.length(); i++){
        ll s = T[T.length()-1-i]-65;
        b += s*pow(5, i);
    }
    ll c = a+b;
    vector<char> A;
    if(c == 0) A.push_back('A');
    while(c != 0){
        char r = (c%5+65);
        c /= 5;
        A.push_back(r);
    }
    for(ll i = 0; i < A.size(); i++){
        cout << A[A.size()-1-i];
    }
    return 0;
}