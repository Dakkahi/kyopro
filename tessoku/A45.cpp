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
    char C;
    cin >> N >> C;
    char A[N+1];
    ll score = 0;
    for(ll i = 1; i <= N; i++) {
        cin >> A[i];
        if(A[i] == 'B') score += 1;
        if(A[i] == 'R') score += 2;
    }

    score %= 3;
    ll judge = 0;
    if(C == 'R') judge = 2;
    if(C == 'B') judge = 1;
    if(judge == score) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}