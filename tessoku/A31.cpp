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
    ll N;
    cin >> N;

    ll divable_3 = N/3;
    ll divable_5 = N/5;
    ll divable_15 = N/15;
    cout << divable_3 + divable_5 - divable_15 << endl;
    return 0;
}