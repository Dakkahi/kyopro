#include<iostream>
#include<algorithm>
#include<vector>
#include <cmath>
#include <string>
using namespace std;

int main(){
    string A, B;
    cin >> A >> B;

    ;

    string C = " " + A+B;

    int len = C.length() - 1;

    int tree[len];
    for(int i = 1; i <= len; i++) {
        tree[i] = C[i] - 96;
        //cout << tree[i] << endl;
    }

    for(int i = 1; i <= len-1; i++){
        for(int j = 1; j <= len - i; j++){
            tree[j] += tree[j+1];
            //if(j == len - 1) tree[j] = 0;
        }
        if(tree[i] > 101) tree[i] -= 101;
    }

    cout << tree[1] << endl;
    return 0;
}