#include <bits/stdc++.h>
using namespace std;

char upper(char c)
{
    if (c >= 'A' && c <= 'X')
        return c += 2;
    else if (c == 'Y')
        return 'A';
    else if (c == 'Z')
        return 'B';
    return c;
}
char lower(char c)
{
    if (c >= 'c' && c <= 'z')
        return c -= 2;
    else if (c == 'a')
        return 'y';
    else if (c == 'b')
        return 'z';
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
