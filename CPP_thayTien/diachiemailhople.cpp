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
        int cnt1, cnt2, cnt3;
        cnt1 = cnt2 = cnt3 = 0;
        int k = s.find('@');
        int check = 1;
        if (k == -1)
        {
            cout << "NO" << endl;
            continue;
        }

        for (int i = 0; i < s.size(); i++)
        {
            if ((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9') || s[i] == '.' || s[i] == '_' || s[i] == '@')
            {
                if (i < k)
                {
                    cnt1++;
                    if (s[i] == '@')
                    {
                        check = 0;
                        break;
                    }
                }

                if (i == k && (cnt1 > 64 || cnt1 == 0))
                {
                    check = 0;
                    break;
                }
                if (i > k)
                {
                    cnt2++;
                    if (s[i] == '@')
                    {
                        check = 0;
                        break;
                    }
                    if (s[i] == '.')
                    {
                        cnt3++;
                    }
                }

                if (s[k + 1] == '.' || s[s.size() - 1] == '.')
                {
                    check = 0;
                }
            }
            else
            {
                check = 0;
                break;
            }
        }

        if (check && cnt3 > 0 && cnt2 <= 254 && cnt2 > 0)
        {
            cout << "YES" << endl;
        }
        else
            cout << "NO" << endl;
    }
}
