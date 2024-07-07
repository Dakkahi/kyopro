#include <iostream>
#include <string>
#include <map>
#include<algorithm>
#include<cmath>
#include<queue>
using namespace std;
using ll = long long;

int main(){
    ll N, M;
    cin >> N >> M;
    string s[N+1];

    for(ll i = 1; i <= N; i++)cin >> s[i];

    ll len;
    ll start = 1;
    ll rest = M;
    ll Mx = 0;
    for(ll end = 1; end <= N; end++){
        if(s[end] == "work") rest--;

        while(rest < 0){
            if(s[start] == "work") rest++;
            start++;
        }
        Mx = max(Mx, end - start+1);
    }
    cout << Mx << endl;
    return 0;
}