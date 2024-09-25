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

int  main(){
    ll N;
    cin >> N;
    ll A[N+1];
    for(ll i  =1; i <= N; i++) cin >> A[i];

    sort(A+1, A+N+1);
    cout << A[N] + A[N-1] << endl;
    return 0;
}