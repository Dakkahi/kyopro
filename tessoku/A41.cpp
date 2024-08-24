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
    string S;
    cin >> S;

    string ans = "No";
    for(ll i = 0; i < N-2; i++){
        if(S[i] == S[i+1] && S[i+1] == S[i+2]){
            ans = "Yes";
            break;
        }
    }
    cout << ans << endl;
    return 0;
}