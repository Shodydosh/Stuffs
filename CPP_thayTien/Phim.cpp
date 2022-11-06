#include <bits/stdc++.h>

using namespace std;

struct Movie
{
    string code;
    string name;
    string date;
    string type;
    string num;
    int index;
    int epNum;
};

bool cmp(Movie a, Movie b)
{
    if (a.date != b.date)
        return a.date > b.date;
    if (a.name != b.name)
        return a.name > b.name;
    return a.epNum > b.epNum;
}

int main()
{
    int m, n;
    cin >> m >> n;
    vector<string> theLoai(m);
    Movie Phim[n];

    cin.ignore();
    for (int i = 0; i < m; i++)
    {
        getline(cin, theLoai[i]);
    }

    // for (int i = 0; i < m; i++)
    //     cout << theLoai[i];

    for (int i = 0; i < n; i++)
    {
        Phim[i].index = i + 1;
        getline(cin, Phim[i].code);
        getline(cin, Phim[i].date);
        getline(cin, Phim[i].num);
        cin >> Phim[i].epNum;

        string c = Phim[i].code;
        int tmp;
        tmp = (c[2] - '0') * 100;
        tmp += (c[3] - '0') * 10;
        tmp += c[4] - '0';
        Phim[i].type = theLoai[tmp - 1];
        cin.ignore();
    }

    sort(Phim, Phim + n, cmp);

    for (int i = 0; i < n; i++)
    {
        if (Phim[i].index >= 100)
            cout << "P";
        else if (Phim[i].index >= 10)
            cout << "P0";
        else
            cout << "P00";

        cout << Phim[i].index << ' ';
        cout << Phim[i].type << ' ';
        cout << Phim[i].date << ' ';
        cout << Phim[i].num << ' ';
        cout << Phim[i].epNum << endl;
    }
}