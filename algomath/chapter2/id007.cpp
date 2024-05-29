#include<iostream>
using namespace std;

int main(){
    int N, X, Y;
    cin >> N >> X >> Y;

    int cnt = 0;
    for (int i = 1; i <= N; i++){
        if(i%X == 0|| i%Y == 0) cnt ++;
    }
    cout << cnt << endl;;
    return 0;
}