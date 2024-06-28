#include <iostream>
#include <string>
#include <map>
#include<algorithm>
#include<cmath>
#include<queue>
using namespace std;
using ll = long long;

vector<char> G[50*50+1];
vector<bool> visited(50*50+1, false);
ll len = 1;


int main(){
    ll H, W;
    cin >> H >> W;
    string s[H+2];
    string v = "";
    for(ll j = 0; j <= W+1; j++) v +='.';

    for(ll i = 0; i <= H+1; i++){
        if(i == 0 || i == H+1){
            s[i] = v;
        }
        else{
            cin >> s[i];
            s[i] = '.' + s[i] + '.';//i行j列はs[i][j]
        }
    }

    ll cnt = 0;
    for(ll i = 1; i <= H; i++){
        for(ll j = 1; j <= W; j++){
            if(s[i][j] == '#'){
                cnt += 4;
                if(s[i][j-1] == '#') cnt--;
                if(s[i][j+1] == '#') cnt--;
                if(s[i-1][j] == '#') cnt--;
                if(s[i+1][j] == '#') cnt--;
            }
        }
    }
    cout << cnt << endl;
    return 0;
}