#include <iostream>
#include <string>
#include <map>
#include<algorithm>
#include<cmath>
#include<queue>
using namespace std;
using ll = long long;

int main(){
    string S;
    cin >> S;
    ll N;
    cin >> N;

    bool flag = false;
    string T;
    for(ll i = 1; i <= N; i++) {
        cin >> T;
        if(T == S){
            flag = true;
            break;
        }
    }
    if(flag == true) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;

    
}