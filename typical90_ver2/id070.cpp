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
    ll N;
    cin >> N;
    ll X[N+1], Y[N+1];
    for(ll i = 1; i <= N; i++) {
        cin >> X[i] >> Y[i];
    }

    //X, Y独立で考えると良い
    sort(X+1, X+N+1);
    sort(Y+1, Y+N+1);

    ll cX = 0;
    ll cY = 0;
    cX = X[(N+1)/2];
    cY = Y[(N+1)/2];

    ll sum = 0;

    for(ll i = 1; i <= N; i++){
        sum += abs(cX - X[i]);
        sum += abs(cY - Y[i]);
    }

    cout << sum << endl;
    return 0;

}