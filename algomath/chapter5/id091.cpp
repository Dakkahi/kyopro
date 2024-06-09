#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
using namespace std;
using ll = long long;

int main(){
    ll N, X;
    cin >> N >> X;
    ll sum = 0;
    for(ll a = 1; a <= min(N-2,X/3); a++){
        for(ll b = a+1; b <= min(N-1,X/2); b++){
            for(ll c = b+1; c <= min(N,X); c++){
                if(a+b+c == X) sum ++;
            }
        }
    }
    cout << sum << endl;
    return 0;

}