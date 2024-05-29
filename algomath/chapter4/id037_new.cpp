#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;


long long vector_prod(long long x1,long long x2, long long y1, long long y2){
    return x1*y2 - x2*y1;
}

long long scalar_prod(long long x1,long long x2, long long y1, long long y2){
    return x1*x2 + y1*y2;
}


int main(){
    long long x1,y1, x2, y2, x3, y3, x4, y4;
    cin >> x1 >> y1;
    cin >> x2 >> y2;
    cin >> x3 >> y3;
    cin >> x4 >> y4;
    string ans = "None";

    long long val1 = vector_prod(x3-x1, x4-x1, y3-y1, y4-y1);
    long long val2 = vector_prod(x3-x2, x4-x2, y3-y2, y4-y2);

    if(val1*val2 < 0) ans = "Yes";
    else if(val1*val2 > 0) ans = "No";

    else if(val1*val2 == 0){
        //まずは点が一致するとき
        if((x1 == x3 && y1 == y3) || (x2 == x3 && y2 == y3) || (x1 == x4 && y1 == y4) || (x2 == x4 && y2 == y4)) ans = "Yes";

        //平行なとき
        if(val1 == 0){ //1,3,4が同一線分上
            if(scalar_prod(x3-x1, x4-x1, y3-y1, y4-y1) < 0) ans = "Yes";
            else if(scalar_prod(x3-x1, x3-x2, y3-y1, y3-y2) < 0 || scalar_prod(x3-x1, x4-x2, y3-y1, y4-y2) < 0) ans = "Yes";
            else ans = "No";
        }

        if(val2 == 0){//2,3,4が同一線分上
            if(scalar_prod(x3-x2, x4-x2, y3-y2, y4-y2) < 0) ans = "Yes";
            else if(scalar_prod(x3-x2, x3-x1, y3-y2, y3-y1) < 0 || scalar_prod(x3-x2, x4-x1, y3-y2, y4-y1) < 0) ans = "Yes";
            else ans = "No";
        }
        
    }
    else ans = "No";

    cout << ans << endl;
    return 0;
}

