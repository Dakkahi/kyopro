#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

int main(){
    ll N;
    cin >> N;
    string S, T;
    cin >> S;
    cin >> T;

    ll b = 0;
    ll w = 0;

    for(ll i = 0; i < N; i++){
        if(S[i] == 'W') w++;
        if(T[i] == 'W') w--;
    }
    if(b != 0){
        cout << -1 << endl;
        return 0;
    }
    else{
        
    }
}