#include <bits/stdc++.h>
using namespace std;

string cal(int n)
{
    if (n >= 120 && n <= 218)
        return "Bao Binh";
    if (n >= 219 && n <= 320)
        return "Song Ngu";
    if (n >= 321 && n <= 419)
        return "Bach Duong";
    if (n >= 420 && n <= 520)
        return "Kim Nguu";
    if (n >= 521 && n <= 620)
        return "Song Tu";
    if (n >= 621 && n <= 722)
        return "Cu Giai";
    if (n >= 723 && n <= 822)
        return "Su Tu";
    if (n >= 823 && n <= 922)
        return "Xu Nu";
    if (n >= 923 && n <= 1022)
        return "Thien Binh";
    if (n >= 1023 && n <= 1122)
        return "Thien Yet";
    if (n >= 1123 && n <= 1221)
        return "Nhan Ma";
    if (n >= 1222 && n <= 1319)
        return "Ma Ket";
    return "0";
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a, b;
        cin >> b >> a;
        if (a == 1 && b <= 19)
            a = 13;
        a = a * 100 + b;
        cout << cal(a) << endl;
    }
}