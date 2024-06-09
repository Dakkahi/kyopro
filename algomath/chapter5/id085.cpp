#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
using ll = long long;

int main(){
    ll N, X, Y;
    cin >> N >> X >> Y;

    for(ll a = 1; a <= N; a++){
        for(ll b = a; b <= N; b++){
            for(ll c = b; c <= N; c++){
                for(ll d = c; d <= N; d++){
                    if(a+b+c+d == X && 1LL*a*b*c*d == Y){ 
                        cout << "Yes" << endl;
                        return 0;
                    }
                }
            }
        }
    }
    cout << "No" << endl;
    return 0;
}