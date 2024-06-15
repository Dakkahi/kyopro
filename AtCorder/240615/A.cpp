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
    string S, T;
    cin >> S >> T;

    string A = "AtCoder";
    string B = "Land";

    if(S == A && B == T) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0; 

}