#include<iostream>
using namespace std;

int func(int N){
    if(N == 1) return N;
    return N*func(N-1);
}

int main(){
    int N;
    cin >> N;

    int ans = func(N);
    cout << ans << endl;
    return 0;
}