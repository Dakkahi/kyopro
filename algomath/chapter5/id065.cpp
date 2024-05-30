#include <iostream>
#include<vector>
using namespace std;

int main(){
    long long H, W;
    cin >> H >> W;

    long long sum = H*W;

    if(H == 1 || W == 1) cout << 1 << endl;
    //角で進めるのはますの座標の輪が偶数のマスのみ
    else{
    if(sum%2 == 0) cout << sum/2 << endl;
    else cout << (sum+1)/2 << endl;
    }
    return 0;
}