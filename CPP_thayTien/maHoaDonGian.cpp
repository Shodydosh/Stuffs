#include <bits/stdc++.h>
using namespace std;

char upper(char c)
{
    if (c >= 'C' && c <= 'Z')
        return c -= 2;
    else if (c == 'A')
        return 'Y';
    else if (c == 'B')
        return 'Z';
    return c;
}
char lower(char c)
{
    if (c >= 'a' && c <= 'x')
        return c += 2;
    else if (c == 'y')
        return 'a';
    else if (c == 'z')
        return 'b';
    return c;
}

int main()
{
    string s;
    getline(cin, s);
    stringstream ss(s);
    string word;
    string ans;
    while (ss >> word)
    {
        for (int i = 0; i < word.size(); i++)
        {
            word[i] = upper(word[i]);
            word[i] = lower(word[i]);
            ans += word[i];
        }
        ans += " ";
    }
    ans.pop_back();
    cout << ans;
}
