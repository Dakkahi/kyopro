#include<iostream>
using namespace std;

int main() {
  
  int N;
  cin >> N;
  long long X[N+9], Y[N+9];
  for (int i=0; i<N; i++) {
    cin >> X[i] >> Y[i];
  }
  long long A, B;
  cin >> A >> B;
  
  int cnt = 0;
  for (int i=0; i<N; i++) {
    long long xa = X[i] - A;
    long long ya = Y[i] - B;
    long long xb = X[(i+1)%N] - A;
    long long yb = Y[(i+1)%N] - B;
    if (ya > yb) {
      swap(xa, xb);
      swap(ya, yb);
    }
    if (ya<=0 && 0<yb && xa*yb-xb*ya<0) {
      cnt = cnt + 1;
    }
  }
  
  if (cnt%2==1) {
    cout << "INSIDE" << endl;
  }
  else {
    cout << "OUTSIDE" << endl;
  }
  
}