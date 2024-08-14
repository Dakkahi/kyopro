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
    ll A, B;
    cin >> A >> B;

    ll prod = A*B;

    while(A != 0 && B != 0){
        if(A > B) A %= B;
        else B %= A;
    }
    if(A == 0) cout << prod/B << endl;
    else cout << prod/A << endl;
    return 0;
}