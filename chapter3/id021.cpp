#include<iostream>
using namespace std;

int main(){
    int n,r;
    cin >> n >> r;

    int a = 1;
    int b = 1;
    for(int i = 2; i <= r; i++) b *= i;
    for(int j = 0; j < r; j++) a *= (n-j);

    cout << a/b << endl;
    return 0;
}