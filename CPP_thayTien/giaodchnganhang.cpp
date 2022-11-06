#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    cin.ignore();
    while (t--)
    {
        string s;
        getline(cin, s);
        int n;
        cin >> n;
        long long a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        long long sum = 0;
        cin.ignore();
        for (int i = 0; i < n; i++)
        {
            if (a[i] < 0)
                sum += a[i];
        }

        if (sum <= -1e8)
            cout << "YES";
        else
            cout << "NO";
        cout << endl;
    }
}
