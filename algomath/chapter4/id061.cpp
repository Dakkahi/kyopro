#include <iostream>
using namespace std;

int main(){
    long long N;
    cin >> N;
    bool flag = false;

    long long M = N+1;
    //おそらくだが，2^k-1で必ず負け，それ以外か基本勝つ

    while(M != 1){
        if(M%2 == 1){
            flag = true;
            break;
        }
        M = M/2;
    }
    if(flag == false) cout << "Second" << endl;
    else cout << "First" << endl;
    return 0;
    
}