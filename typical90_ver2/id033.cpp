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
    ll H, W;
    cin >> H >> W;

    ll h = (H+1)/2;
    ll w = (W+1)/2;

    if(H == 1 || W == 1) cout << H*W << endl;
    else cout << h*w << endl;
    return 0;
}