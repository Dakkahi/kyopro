#include<iostream>
#include<algorithm>
#include<vector>
#include <cmath>
#include <string>
#include <cctype>
using namespace std;

int main(){
    using std::string;
    int N, M;
    cin >> N >> M;

    string s[N*M+1];
    for(int i = 1; i<= N*M; i++) cin >> s[i];  //i行j列は(i-1)*M + j
    cout << s[6] << endl;
    return 0;


}