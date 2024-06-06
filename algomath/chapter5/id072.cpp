#include <iostream>
#include<cmath>
#include<algorithm>
using namespace std;
using ll = long long;

int main(){
    ll A, B;
    cin >> A >> B;

    ll max = 0;
    for(ll i = 1; i <= B; i++){
        if(B/i - (A+i-1)/i >= 1) max = i;
    }

    cout << max << endl;
    return 0;
}