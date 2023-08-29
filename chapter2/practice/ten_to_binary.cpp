#include<iostream>
#include<string>
using namespace std;

int N;
string ans = "";

int main(){
    cin >> N;
    while(N >= 1){
        if(N % 2 == 0) ans = "0" + ans;
        else ans = "1" + ans;

        N = N/2;
    }
    cout << ans << endl;
    return 0;
}