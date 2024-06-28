#include <iostream>
#include <string>
#include <map>
#include<algorithm>
#include<cmath>
#include<queue>
#include<vector>
using namespace std;
using ll = long long;

string replace(string S, string T){
    string ans = "";
    for(ll i = 0; i < S.length(); i++){
        for(ll j = 0; j < 26; j++){
            if(S[i] == T[j]){
                char add = j+97;
                ans = ans + add;
                break;
            }
        }
    }
    return ans;
}


int main(){
    ll N; //置換回数
    string T;
    cin >> N >> T;
    string S;
    string stack = " ";
    bool flag = false;
    while(1){
        cin >> S;
        if(S == stack) break;
        stack = S;
        string ans = S;
        for(ll i = 1; i <= N; i++){
            ans = replace(ans, T);
        }
        if(flag == false){
            flag = true;
            cout << ans;
        }
        else{
            cout << " " << ans;
        }
    }
    return 0;
}