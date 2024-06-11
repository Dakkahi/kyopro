#include <iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
using ll = long long;

int main(){
    string S[3] = {"gdf", "andr", "k5467"};
    sort(S, S+3);
    for(ll i = 0; i < 3; i++){
        cout << S[i] << endl;
    }
    return 0;
}