#include <bits/stdc++.h>
using namespace std;
struct Exams
{
    int code;
    float share, react, sum;
};
float score(Exams a)
{
    a.sum = (float)(a.share * 7 + a.react * 3) / (float)10;
    return a.sum;
}
bool cmp(Exams a, Exams b)
{
    return a.sum > b.sum;
}
int main()
{
    int n;
    cin >> n;
    Exams a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].code >> a[i].share >> a[i].react;
        a[i].sum = score(a[i]);
    }

    sort(a, a + n, cmp);

    for (int i = 0; i < 7; i++)
    {
        cout << a[i].code << ' ';
    }
    return 0;
}