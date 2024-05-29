//組み合わせ
#include<iostream>
using namespace std;

int main(){
    int N, A[200],a,b,c,d;
    a = 0;
    b = 0;
    c = 0;
    d = 0;
    int ans = 0;
    cin >> N;
    for(int i = 1; i<= N; i++) cin >> A[i];

    for(int i = 1; i<= N; i++){
        if(A[i] == 100) a++;
        if(A[i] == 200) b++;
        if(A[i] == 300) c++;
        if(A[i] == 400) d++;
    }
    ans = a*d + c*b;
    cout << ans << endl;
    return 0;
}