#include <iostream>
#include<cmath>
#include<algorithm>
using namespace std;
using ll = long long;

int main(){
    ll N, L, R;
    cin >> N >> L >> R;
    
    ll i = 1;
    while(i < L){
        if(i != N) cout << i << " ";
        else cout << i << endl;
        i ++;
    }

    ll j = R;
    while(j >= L){
        cout << j << " ";

        j --;
    }

    ll k = R+1;
    while(k <= N){
        if(k != N) cout << k << " ";
        else cout << k << endl;
        k ++;
    }

    return 0;
}