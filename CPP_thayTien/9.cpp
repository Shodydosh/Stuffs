#include <bits/stdc++.h>
using namespace std;
struct Exams
{
    int ma;
    float share, rec, tong;
};
float score(Exams a)
{
    a.tong = (float)(a.share * 7 + a.rec * 3) / (float)10;
    return a.tong;
}
bool cmp(Exams a, Exams b)
{
    return a.tong > b.tong;
}
int main()
{
    int n;
    cin >> n;
    Exams a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].ma >> a[i].share >> a[i].rec;
        a[i].tong = score(a[i]);
    }
    sort(a, a + n, cmp);
    for (int i = 0; i < 7; i++)
        cout << a[i].ma << ' ';
}