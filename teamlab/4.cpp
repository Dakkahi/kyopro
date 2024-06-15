#include <iostream>
#include <string>
#include <map>
#include<algorithm>
#include<cmath>
#include<queue>
#include<vector>
using namespace std;
using ll = long long;

//10 の(正の)平方根の値は √10 = 3.16227766 ⋯ で、その整数部分(小数点以下を切り捨てた値)は 3 になります。

//同様に、1 から 10 までの整数について平方根の整数部分の値を求めると

//1,1,1,2,2,2,2,2,3,3

//となり、それらの総和は 19 となります。

//それでは、「1 から N までの整数についての平方根の整数部分の総和が 1000000 以上になる」という条件を満たすような最小の整数 N を求めてください。

//1~3 4~8 9~15 



int main(){
    ll N = 1;
    ll sum = 0;
    ll tmp = 1000000;
    while(sum < tmp){
        ll val;
        for(ll i = 2; i <= tmp; i++){
            if(N < i*i){
                val = i-1;
                break;
            }
        }
        sum += val;
        N ++;
    }

    cout << N-1 << endl;
    return 0;
}
