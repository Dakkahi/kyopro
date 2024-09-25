#include <iostream>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <cmath>
#include <stack>
#include <queue>
#include <vector>

using namespace std;
using ll = long long;

int main(){
    ll N;
    cin >> N;

    char l = '(';
    char r = ')';

    string S[(1LL << N) + 1];

    for(ll i = 1; i <= (1LL << N); i++){
        S[i] = "";
        for(ll j = 0; j < N; j++){
            if(((i-1) & (1LL << j)) != 0LL){
                S[i] = r + S[i];
            }else{
                S[i] = l + S[i];
            }
        }
    }

    //for(ll i = 1; i <= 1LL << N; i++) cout << S[i] << endl;
    bool flag;
    for(ll i = 1; i <= (1LL << N); i++){
        stack<char> T;
        flag = true;
        for(ll j = 0; j < N; j++){
            if(S[i][j] == l) T.push('(');
            else{
                if(T.size() == 0) {
                    flag = false;
                    break;
                }
                else T.pop();
            }
        }
        if(flag == true && T.size() == 0) cout << S[i] << endl;
    }
    return 0;
}