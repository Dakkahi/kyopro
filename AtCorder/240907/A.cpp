#include <iostream>
#include <string>
#include <map>
#include<algorithm>
#include<cmath>
#include<queue>
#include<vector>
using namespace std;
using ll = long long;

int main(){
    ll L, R;
    cin >> L >> R;

    if(L == 1 && R == 0) cout << "Yes" << endl;
    else if(R == 1 && L == 0) cout << "No" << endl;
    else cout << "Invalid" << endl;
    return 0;
}