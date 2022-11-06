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

        int cnt = 0;
        stringstream ss(s);
        string ans;
        while (ss >> s)
        {
            if (ans.size() < 100)
            {
                if (ans.size() + s.size() > 100)
                    break;
                else
                    ans += s + " ";
            }
            else if (ans.size() == 100)
                ans += s + " ";
        }
        ans.pop_back();
        cout << ans << endl;
    }
    return 0;
}