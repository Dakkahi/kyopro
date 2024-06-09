#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include<string>
using namespace std;
using ll = long long;

int main(){
    ll N;
    cin >> N;
    string S;
    cin >> S;

    ll depth = 0;//(で+1, )で-1していき、depthが負にならず、かつ最後に0となればOK
    for(ll i = 0; i < N; i++){
        if(S[i] == '('){
            depth += 1;
        }
        if(S[i] == ')'){
            depth -= 1;
        }
        if(depth < 0){
            cout << "No" << endl;
            return 0;
        }
    }
    if(depth == 0) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}