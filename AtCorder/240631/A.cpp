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
    string S;
    cin >> S;
    map<char, int> M; 

    for(ll i = 1; i <= 3; i++){
        M[S[i]] = i;
    }
    if(M['R'] < M['M']) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}