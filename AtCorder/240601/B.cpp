#include <iostream>
#include<cmath>
#include<algorithm>
using namespace std;
using ll = long long;

int main(){
    ll N, M;
    cin >> N >> M;
    ll A[M+1];
    for(ll i = 1; i <= M; i++) cin >> A[i];

    ll X[N*M+1];
    for(ll i = 1; i <= M*N; i++) cin >> X[i]; //(i-1)*M + j;

    bool flag = true;

    for(ll j = 1; j <= M; j++){
        ll sum = 0;
        for(ll i = 1; i <= N; i++){
            sum += X[(i-1)*M + j];
            }
            if(sum < A[j]){
                flag = false;
                break;
            }
        }
    
    if(flag == true) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}