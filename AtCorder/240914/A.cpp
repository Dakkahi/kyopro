#include <iostream>
#include <string>
#include <map>
#include<algorithm>
#include<cmath>
#include<queue>
#include<vector>
#include<stack>
using namespace std;
using ll = long long;

int main(){
    char a, b, c;
    cin >> a >> b >> c;
    
    if(a == '<' && b == '>') cout << 'A' << endl;
    if(a == '<' && b == '<' && c == '<') cout << 'B' << endl;
    if(a == '<' && b == '<' && c == '>') cout << 'C' << endl;
    if(a == '>' && b == '<') cout << 'A' << endl;
    if(a == '>' && b == '>' && c == '>') cout << 'B' << endl;
    if(a == '>' && b == '>' && c == '<') cout << 'C' << endl;

    return 0;

}