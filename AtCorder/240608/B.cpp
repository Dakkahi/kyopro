#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include<string>
using namespace std;
using ll = long long;

int main(){
    string S;
    cin >> S;

    int len = S.length();

    int mini = 0;
    int big = 0;
    for(int i = 0; i < len; i++){
        int moji = S[i];
        if(moji > 90) mini ++;
        else big++;
    }
    if(mini > big){
        for(int i = 0; i < len; i++){
            int moji = S[i];
            if(moji <= 90){
                int num = moji + 32;
                S[i] = S[i] + 32;
            }
        }
    }
    else{
        for(int i = 0; i < len; i++){
            int moji = S[i];
            if(moji > 90){
                int num = moji - 32;
                S[i] = S[i] - 32;
            }
        }
    }

    cout << S << endl;
    return 0;

}