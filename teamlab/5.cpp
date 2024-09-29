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
    ll cnt = 1;

    ll sum = 0;

    for(ll i = 700; i >= 1; i--){
        if(sum + i <= 5000){
            sum += i;
        }else{
            cnt++;
            sum = i;
        }
    }
    cout << cnt << endl;
    return 0;
}