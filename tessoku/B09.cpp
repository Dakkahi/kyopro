// B09
#include <iostream>
using namespace std;

int main() {
	int N, X1, Y1, X2, Y2;
  int input[1510][1510];
  int output[1510][1510];
	// 入力
  cin >> N;
  for (int i = 1; i <= N; i++) {
    cin >> X1 >> Y1 >> X2 >> Y2;
    input[X1][Y1] += 1;
    input[X1][Y2] -= 1;
    input[X2][Y1] -= 1;
    input[X2][Y2] += 1;
  }
  // 横方向に加算
  for (int i = 0; i <= 1500; i++) {
     for (int j = 0; j <= 1500; j++) {
      output[i][j] = output[i][j - 1] + input[i][j];
     }
  }

  // 縦方向に加算
  for (int i = 0; i <= 1500; i++) {
     for (int j = 0; j <= 1500; j++) {
      output[i][j] = output[i - 1][j] + output[i][j];
     }
  }

  int sum = 0;
  for (int i = 0; i <= 1500; i++) {
    for (int j = 0; j <= 1500; j++) {
      if (output[i][j] > 0) {
        sum += 1;
      }
    }
  }
  cout << sum;
	return 0;
}