#include <iostream>
using namespace std;

int main(){
    int N;
    cin >> N;
    int a[N + 9];

    a[1] = 1;
    a[2] = 1;
    for(int i = 3;  i <= N; i++){
        a[i] = (a[i-1] + a[i-2])%1000000007;
    }
    cout << a[N] << endl;
    return 0;

}