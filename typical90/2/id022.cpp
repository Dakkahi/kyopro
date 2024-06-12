#include <iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
using ll = long long;

ll gdc(ll a, ll b){
    while(a*b != 0){
        if(a> b) a %= b;
        else b %= a;
    }
    if(a>b) return a;
    else return b;
}

int main(){
    ll A, B, C;
    cin >> A >> B >> C;
    ll g = gdc(A, gdc(B,C));
    
    ll cnt = A/g + B/g + C/g- 3;

    cout << cnt << endl;
    return 0;

}