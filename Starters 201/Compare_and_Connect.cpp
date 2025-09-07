#include <bits/stdc++.h>

using namespace std;
void solve()
{
    int n, m;
    cin >> n >> m;

    if (n >= 1 && m >= 1)
    {
        for (int i = 0; i < 2 * n; ++i)
        {
            cout << '<';
        }
        for (int i = 0; i < m - 1; ++i)
        {
            cout << "><";
        }
        cout << '>';
    }
    else if (m == 0)
    {
        for (int i = 0; i < 2 * n - 3; ++i)
        {
            cout << '<';
        }
        cout << "=<";
    }
    else
    {
        for (int i = 0; i < m - 2; ++i)
        {
            cout << "><";
        }
        cout << ">=>";
    }
    cout << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}