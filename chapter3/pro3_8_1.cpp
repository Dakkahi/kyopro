#include<iostream>
#include<algorithm>
using namespace std;

long long N, X, A[100009];

int main(){
    cin >> N >> X;
    for(int i = 1; i <= N; i++) cin >> A[i];

    sort(A + 1, A + N + 1);

    //binary search
    int left = 1;
    int right = N;
    while(left <= right){
        int mid = (left + right)/2;
        if(A[mid] == X){
            cout << "Yes" << endl;
            return 0;
        }
        else if(X < A[mid]){
            right = mid - 1;
        }
        else{
            left = mid + 1;
        }
    }
    cout<< "No" << endl;
    return 0;
}