//数字を2進法にしてビット演算をする
#include<iostream>
using namespace std;

int main(){
    int a, b;
    cin >> a >> b;
    cout << (a & b) << endl;
    cout << (a | b) << endl;
    cout << (a ^ b) << endl;
    return 0;
}