#include <bits/stdc++.h>
#include <fstream>

using namespace std;

char lowerHandle(char c)
{
    if (c >= 'A' && c <= 'Z')
    {
        return c += 32;
    }
    return c;
}
bool cmp(string a, string b)
{
    return a < b;
}

int main()
{
    string s[600];
    int cnt = 0;
    ifstream file;
    file.open("CONTACT.in");
    string tmp;
    while (file >> tmp)
    {
        for (int i = 0; i < tmp.size(); i++)
        {
            tmp[i] = lowerHandle(tmp[i]);
        }
        s[cnt++] = tmp;
    }
    set<string> se1;
    for (string x : s)
    {
        se1.insert(x);
    }

    vector<string> ans;

    for (string x : se1)
    {
        if (x.size() != 0)
            ans.push_back(x);
    }

    sort(ans.begin(), ans.end(), cmp);
    for (string x : ans)
    {
        cout << x << endl;
    }

    return 0;
}
