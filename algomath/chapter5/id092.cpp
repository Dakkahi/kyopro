#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
using namespace std;
using ll = long long;

int main(){
    ll N;
    cin >> N;
    ll min = 2*(N+1);
    //素因数分解しながら解く
    for(ll i = 2; i*i <= N; i++){
        if(N%i == 0){
            ll len = 2*(i+N/i);
            if(len < min) min = len;
        }
    }
    cout << min << endl;
    return 0;
}