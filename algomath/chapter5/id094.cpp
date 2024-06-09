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
    ll B[N];

    ll sum = 0;
    for(ll i = 1; i <= N-1; i++) cin >> B[i];

    for(ll i = 1; i <= N; i++){
        if(i == 1) sum += B[i];
        else if(i < N) sum += min(B[i],B[i-1]);
        else sum += B[i-1];
    }
    cout << sum << endl;
    return 0;
}