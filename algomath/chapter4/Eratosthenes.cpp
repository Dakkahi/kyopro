#include<iostream>
#include<cmath>
using namespace std;


int main(){
    int N;
    cin >> N;
    bool prime [N+4];
    for(int i = 2; i<= N; i++) prime[i] = true;

    for(int i = 2; i*i <= N; i++){
        if(prime[i] == true){
            for(int j = 2*i; j <= N; j += i) prime[j] = false;
        }
    }

    for(int i = 2; i<= N; i++){
        if(prime[i] == true) cout << i << endl;
    }
    return 0;
}