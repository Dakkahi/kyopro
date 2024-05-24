#include <iostream>
#include<algorithm>

using namespace std;

long long cross(long long x1, long long y1, long long x2, long long y2)
{
    return (x1 * y2 - x2 * y1);
}

int main()
{
    //点A(x1y1),B(x2y2),C(x3y3),D(x4y4)がある
    //直線ABと点C,Dの位置関係を調べる
    //点C,Dが直線ABの両側に分かれているとき　直線ABと直線CDは交差する
    //ベクトルABとベクトルACの絶対値を外した外積とベクトルABとベクトルADの絶対値を外した外積の正負が
    //異なるとき交差する

    long long x1, x2, x3, x4, y1, y2, y3, y4;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
    if (min(x1, x2) > max(x3, x4) || max(x1, x2) < min(x3, x4))
    {
        cout << "No" << endl;
    }
    else if (min(y1, y2) > max(y3, y4) || max(y1, y2) < min(y3, y4))
    {
        cout << "No" << endl;
    }
    else
    {
        long long v_ABAC = cross(x2 - x1, y2 - y1, x3 - x1, y3 - y1);
        long long v_ABAD = cross(x2 - x1, y2 - y1, x4 - x1, y4 - y1);
        long long v_CDCA = cross(x4 - x3, y4 - y3, x1 - x3, y1 - y3);
        long long v_CDCB = cross(x4 - x3, y4 - y3, x2 - x3, y2 - y3);
        if (v_ABAC == 0 && v_ABAD == 0 && v_CDCA == 0 && v_CDCB == 0)
        {
            cout << "Yes" << endl;
        }
        else if (v_ABAC>=0 && v_ABAD <= 0 && v_CDCA>=0 && v_CDCB <= 0)
        {
            cout << "Yes" << endl;
        }
        else if (v_ABAC >= 0 && v_ABAD <= 0 && v_CDCA <= 0 && v_CDCB >= 0)
        {
            cout << "Yes" << endl;
        }
        else if (v_ABAC <= 0 && v_ABAD >= 0 && v_CDCA >= 0 && v_CDCB <= 0)
        {
            cout << "Yes" << endl;
        }
        else if (v_ABAC <= 0 && v_ABAD >= 0 && v_CDCA <= 0 && v_CDCB >= 0)
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }
}