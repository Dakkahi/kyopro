#include <iostream>
#include <string>
#include <map>
#include<algorithm>
#include<cmath>
#include<queue>
#include<vector>
using namespace std;


int main(){
    int a[45];
    for(int i = 0; i <= 44; i++) a[i] = 0;
    a[1] = 1;
    a[2] = 2;
    for(int i = 3; i <= 44; i++){
        a[i] = a[i-1] + a[i-2]-1;
    }
    cout << a[44] << endl;
    return 0;
}