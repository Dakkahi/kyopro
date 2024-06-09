#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
using namespace std;
using ll = long long;

ll GDC(ll a, ll b){
    while(a != 0 && b != 0){
        if(a>b) a %= b;
        else b %= a;
    }
    if(a == 0) return b;
    else return a;

}

int main(){
    ll A, B;
    cin >> A >> B;
    ll thresh = 1000000000000000000;

    ll gdc = GDC(A, B);

    ll a = A/gdc;
    ll b = B/gdc;
    
    //ga'b'の積が10^18より大きいのは10^18をこれらで割っていって小さくなっていけばよい
    ll thresh_1 = thresh/gdc; //コーナーケース用の+1
    ll thresh_2 = thresh_1/a;
    ll thresh_3 = thresh_2/b;

    if(thresh_3 < 1) cout << "Large" << endl;
    
    else cout << a*b*gdc << endl;
    return 0;
}