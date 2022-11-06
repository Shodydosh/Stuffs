#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    float a[n];
    float minVal, maxVal, sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a, a + n);
    minVal = a[0];
    maxVal = a[n - 1];

    int coun = 0;

    for (float x : a)
    {
        if (x != minVal && x != maxVal)
        {
            sum += x;
            coun++;
        }
    }

    cout << fixed << setprecision(2) << (float)sum / (float)coun;
}
