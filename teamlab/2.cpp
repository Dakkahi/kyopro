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

int main(){
    ll N = 1022221200;

    ll cnt = 0;

    for(ll i = 1; i*i <= N; i++){
        if(N%i == 0){
            if(10000 <= i && i <= 99999) cnt++;
            if(10000 <= N/i && N/i <= 99999) cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}