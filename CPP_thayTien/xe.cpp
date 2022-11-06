#include <bits/stdc++.h>

using namespace std;

struct Car
{
    int seatNum, d, m, y;
    string plateNum, type, direction, date;
    long long money;
};

long long cal(int n)
{
    if (n == 5)
        return 10;
    if (n == 7)
        return 15;
    if (n == 2)
        return 20;
    if (n == 29)
        return 50;
    return 70;
}

void inputSingle(Car &A)
{
    cin >> A.plateNum;
    cin >> A.type;
    cin >> A.seatNum;
    cin >> A.direction;
    cin >> A.date;
    A.money = cal(A.seatNum);

    string s = A.date;
    A.d = (s[0] - '0') * 10 + s[1] - '0';
    A.m = (s[3] - '0') * 10 + s[4] - '0';
    A.y = (s[6] - '0') * 1000 + (s[7] - '0') * 100 + (s[8] - '0') * 10 + s[9] - '0';
}

bool cmp(Car a, Car b)
{
    if (a.y != b.y)
        return a.y < b.y;
    if (a.m != b.m)
        return a.m < b.m;
    else
        return a.d < b.d;
}

void output(Car A[], int n)
{
    sort(A, A + n, cmp);
    string day = A[0].date;
    int tmp = 0;
    if (A[0].direction == "IN")
        tmp += A[0].money;
    for (int i = 1; i < n; i++)
    {
        if (A[i].date == day)
        {
            if (A[i].direction == "IN")
            {
                tmp += A[i].money;
            }
        }
        else
        {
            cout << day << ": " << tmp << "000" << endl;
            tmp = 0;
            if (A[i].direction == "IN")
                tmp += A[i].money;
            day = A[i].date;
        }
    }

    if (tmp > 0)
        cout << day << ": " << tmp << "000" << endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    Car car[n];
    cin.ignore();
    for (int i = 0; i < n; i++)
    {
        inputSingle(car[i]);
    }
    output(car, n);
}