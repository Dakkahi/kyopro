#include <iostream>
#include <string>
#include <map>
#include<algorithm>
#include<cmath>
#include<queue>
#include<vector>
using namespace std;
using ll = long long;

int main(){
    string S, T;
    cin >> S >> T;
    bool flag = false;
    ll len = S.length();
    for(ll w = 1; w < len; w++){
        ll div = len/w;
        for(ll c = 1; c <= w; c++){
            string A = "";
            for(ll k = 1; k <= div; k++){
                A = A + S[(k-1)*w+c-1];
            }
            if(A == T) flag = true;
        }
    }
    if(flag == true) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}

