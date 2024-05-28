#include<iostream>
#include<algorithm>
#include<vector>
#include <cmath>
using namespace std;

int main(){
    int N, c;
    cin >> N >> c;
    int t[N+1], time_stack[N+1]; //time_stackはi番目の電車が来る前にどれだけ踏切が降りていたかを格納
    for(int i = 1; i <= N; i++) {
        cin >> t[i];
        time_stack[i] = 0; 
    }

    //int A[t[N+1] + 1], B[t[N+1] + 1];
    

    int max = c;
    if(t[1] < c) max = t[1];
    time_stack[1] = max;
    for(int i = 2; i <= N; i++){
        if(t[i] - t[i-1] <= c){
            time_stack[i] = time_stack[i-1] + (t[i] - t[i-1]);
        }
        else{
            time_stack[i] = c;
        }
        if(max < time_stack[i]) max = time_stack[i];
    }
    cout << max << endl;
    return 0;

}