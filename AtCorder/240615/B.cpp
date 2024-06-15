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
    ll N , A;
    cin >> N >> A;
    ll T[N+1];
    for(ll i = 1; i <= N; i++) cin >> T[i];

    vector<ll> time(N+1, 0);
    for(ll i = 1; i <= N; i++){
        if(i == 1) {
            cout << T[i]+A << endl;
            time[i] = T[i]+A;
        }
        else{
            if(time[i-1] <= T[i]) {
                cout << T[i]+A << endl;
                time[i] = T[i]+A;;
            }
            else{
                time[i] = time[i-1] + A;
                cout << time[i] << endl;
            }
        }
    }
    return 0;
}