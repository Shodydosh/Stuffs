#include <bits/stdc++.h>
using namespace std;

struct SoPhuc
{
    float ao, thuc;
};

SoPhuc binh_phuong_tong(SoPhuc a, SoPhuc b)
{
    SoPhuc ans;
    ans.thuc = (a.thuc + b.thuc - a.ao - b.ao) * (a.thuc + b.thuc + a.ao + b.ao);
    ans.ao = 2 * (a.thuc + b.thuc) * (a.ao + b.ao);
    return ans;
}

void hien_thi(SoPhuc a)
{
    cout << a.thuc << ' ' << '+' << ' ' << a.ao << "i";
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        SoPhuc A;
        SoPhuc B;
        cin >> A.thuc >> A.ao >> B.thuc >> B.ao;
        SoPhuc C = binh_phuong_tong(A, B);
        hien_thi(C);
        cout << endl;
    }
}
