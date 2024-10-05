#include <iostream>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <cmath>
#include <stack>
#include <queue>
#include <vector>

using namespace std;
using ll = long long;

int main(){
    ll N;
    cin >> N;
    ll A[N+1], B[N+1], C[N+1];
    for(ll i = 1; i <= N; i++) {
        cin >> A[i];
    }
    for(ll i = 1; i <= N; i++) {
        cin >> B[i];
    }
    for(ll i = 1; i <= N; i++) {
        cin >> C[i];
    }


    ll mod = 46;

    ll A_mod[46], B_mod[46], C_mod[46];
    for(ll i = 0; i < 46; i++) {
        A_mod[i] = 0;
        B_mod[i] = 0;
        C_mod[i] = 0;
    }

    for(ll i = 1; i <= N; i++){
       A_mod[A[i]%mod] += 1; 
       B_mod[B[i]%mod] += 1; 
       C_mod[C[i]%mod] += 1; 
    }

    //for(ll i = 0; i < 46; i++) cout << A_mod[i] << endl;
    // sort(A+1, A+N+1);
    // sort(B+1, B+N+1);
    // sort(C+1, C+N+1);

    ll cnt = 0;
    for(ll i = 0; i < 46; i++){
        for(ll j = 0; j < 46; j++){
            for(ll k = 0; k < 46; k++){
                if((i+j+k)%46 == 0) {
                    cnt += A_mod[i]*B_mod[j]*C_mod[k];
                    }

                
            }
        }
    }

    cout << cnt << endl;
    return 0;
}