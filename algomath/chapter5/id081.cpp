#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
using ll = long long;

int main(){
    ll N;
    cin >> N;
    ll A[] = {10000, 5000, 1000};
    ll sum = 0;

    for(ll i = 0; i < 3; i++){
        sum += N/A[i];
        N %= A[i];
    }
    cout << sum << endl;
    return 0;
}