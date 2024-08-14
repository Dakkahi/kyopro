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

    cout << (N/3) + (N/5) + (N/7) - (N/15) - (N/21) - (N/35) + (N/105)<< endl;
    return 0;
}