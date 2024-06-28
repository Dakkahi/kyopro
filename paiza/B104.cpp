#include<iostream>
#include<algorithm>
#include<vector>
#include <cmath>
#include <string>
#include <cctype>
using namespace std;
using ll = long long;

int main(){
    ll N, M;
    cin >> N >> M;

    string S[N+1][M+1];
    for(ll i = 1; i <= N; i++){
        for(ll j = 1; j <= M; j++) cin >> S[i][j];
    }

    for(ll j = 1; j <= M; j++){
        ll cnt = 0;
        ll sum = 0;
        for(ll i = 1; i <= N; i++){
            string s = S[i][j];
            bool flag = true;
            for(ll k = 0; k < s.size(); k++){
                if(!isdigit(s[k])){
                    flag = false;
                    break;
                }
            }
            if(flag == true && stoi(s) <= 100){
                cnt++;
                sum += stoi(s);
            }
        }
        if(cnt == 0) cout << 0 << endl;
        else cout << sum/cnt << endl;
    }

    return 0;
}