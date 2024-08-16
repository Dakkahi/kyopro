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
    ll N, K;
    cin >> N >> K;
    if(K < 2*(N-1)) cout << "No" << endl;
    else{
        if((K - 2*(N-1))%2 == 0) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}