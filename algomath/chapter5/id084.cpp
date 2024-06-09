#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
using ll = long long;

int main(){
    ll a, b, c;
    cin >> a >> b >> c;
    if(c - a - b < 0LL) cout << "No" << endl;

    else{
        if((c-a-b)*(c-a-b) > 4*a*b) cout << "Yes" << endl;
        else cout << "No" << endl;
    } 
    return 0;
}