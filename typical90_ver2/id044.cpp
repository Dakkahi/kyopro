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
    ll N, Q;
    cin >> N >> Q;
    ll A[N+1];
    for(ll i = 1; i <= N; i++) cin >> A[i];

    ll shift = 0;
    for(ll i = 1; i <= Q; i++){
        ll T, x, y;
        cin >> T >> x >> y;
        if(T == 2){
            shift += 1;
        }
        if(T == 1){
            swap(A[(x+Q*N-shift-1)%N+1], A[(y+Q*N-shift-1)%N+1]);
        }
        if(T == 3){
            cout << A[(x+Q*N-shift-1)%N+1] << endl;
        }
    }
    return 0;
}