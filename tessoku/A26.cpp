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
    ll Q;
    cin >> Q;
    ll X;

    for(ll i = 1; i <= Q; i++){
        cin >> X;
        if(X == 2 || X == 3) cout << "Yes" << endl;
        else{
            bool flag = true;
            for(ll j = 2; j*j <= X; j++){
                if(X%j == 0){
                    flag =false;
                    break;
                }
            }
            if(flag == true) cout << "Yes" << endl;
            else cout << "No" << endl;
        }
    }
    return 0;
}