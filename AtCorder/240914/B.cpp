#include <iostream>
#include <string>
#include <map>
#include<algorithm>
#include<cmath>
#include<queue>
#include<vector>
#include<stack>
using namespace std;
using ll = long long;

int main(){
    ll N, M;
    cin >> N >> M;
    ll A[M+1];
    char B[M+1];

    map<ll, ll> Mymap;

    for(ll i = 1; i <= M; i++) {
        cin >> A[i] >> B[i];
        string ans = "No";
        if(B[i] == 'M'){
            if(Mymap[A[i]] == 0){
                ans = "Yes";
                Mymap[A[i]] += 1;
            }
        }
        cout << ans << endl;
    }
    return 0;
    
}