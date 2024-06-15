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
    ll N, M;
    cin >> N >> M;

    ll A[N+1], B[M+1];
    for(ll i = 1; i <= N; i++) cin >> A[i];
    for(ll i = 1; i <= M; i++) cin >> B[i];

    sort(A+1, A+N+1);
    sort(B+1, B+M+1);

    ll pay = 0;
    ll flag = 1;
    for(ll i = 1; i <= M; i++){
            while(flag <= N && (A[flag] < B[i])){
                flag ++;
        }
        if(flag > N){
            cout << -1 << endl;
            return 0;
        }
        else{
            pay += A[flag];
            //cout << A[flag] << endl;
            flag ++;
        }
    }
    cout << pay << endl;
    return 0;
}