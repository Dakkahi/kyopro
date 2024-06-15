#include <iostream>
#include <string>
#include <map>
#include<algorithm>
#include<cmath>
#include<queue>
#include<vector>
using namespace std;
using ll = long long;


// 5 文字の英字からなる文字列で以下の条件をすべて満たすものの個数を求めてください。

// 次に挙げる文字のみを含む(同じ文字を 2 回以上含まれてもよい):AEKLNORST
// 文字列のどこかに “OK” が含まれる。



int main(){
    string S = "OKAELNRST";
    string ok = "OK";
    ll cnt = 0;

    ll len = S.length();

    // //全事象からOKがないのを除く
    // ll all = len*len*len*len*len;

    //OKかないもの
    for(int i = 0; i < len; i++){
        for(int j = 0; j < len; j++){
            for(int k = 0; k < len; k++){
                for(int l = 0; l < len; l++){
                    for(int m = 0; m < len; m++){
                        if((i == 0 && j == 1) || (j == 0 && k == 1) ||(k == 0 && l == 1) ||(l == 0 && m == 1)) cnt++;
                    }
                }
            }
        }
    }
    
   cout << cnt << endl;
    return 0;
}