#include <bits/stdc++.h>
using namespace std;

struct Movie
{
    string ma_phim;
    string type;
    string ma;
    string date;
    string name;
    int epNum;
};

bool cmp(Movie a, Movie b)
{
    if (a.date != b.date)
    {
        return a.date > b.date;
    }
    else
    {
        if (a.name != b.name)
        {
            return a.name < b.name;
        }
        return a.epNum > b.epNum;
    }
}

int main()
{
    int n, m;
    vector<string> type;
    cin >> n >> m;
    getchar();
    for (int i = 0; i < n; i++)
    {
        string s;
        getline(cin, s);
        type.push_back(s);
    }
    Movie a[m + 4];
    for (int i = 1; i <= m; i++)
    {
        if (i < 10)
        {
            a[i].ma_phim = "P00" + to_string(i);
        }
        else if (i < 100)
        {
            a[i].ma_phim = "P0" + to_string(i);
        }
        else if (i < 1000)
        {
            a[i].ma_phim = "P" + to_string(i);
        }
        getline(cin, a[i].ma);
        getline(cin, a[i].date);
        getline(cin, a[i].name);
        cin >> a[i].epNum;
        getchar();
        int k = (a[i].ma[2] - '0') * 100 + (a[i].ma[3] - '0') * 10 + (a[i].ma[4] - '0');
        a[i].type = type[k - 1];
    }
    sort(a + 1, a + m + 1, cmp);
    for (int i = 1; i <= m; i++)
    {
        cout << a[i].ma_phim << " " << a[i].type << " ";
        cout << a[i].date << " " << a[i].name << " " << a[i].epNum;
        cout << endl;
    }
    return 0;
}