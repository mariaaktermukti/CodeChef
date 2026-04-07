#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        vector<long long> f(n + 1), a(n + 1);
        for (int i = 1; i <= n; i++)
            cin >> f[i];

        if (n == 2)
        {
            cout << f[2] << ' ' << f[1] << '\n';
            continue;
        }

        for (int i = 2; i <= n - 1; i++)
        {
            a[i] = (f[i + 1] + f[i - 1] - 2LL * f[i]) / 2LL;
        }

        long long g1 = f[1], gn = f[n];
        for (int i = 2; i <= n - 1; i++)
        {
            g1 -= a[i] * (i - 1LL);
            gn -= a[i] * (n - i);
        }

        a[1] = gn / (n - 1LL);
        a[n] = g1 / (n - 1LL);

        for (int i = 1; i <= n; i++)
        {
            cout << a[i] << (i == n ? '\n' : ' ');
        }
    }

    return 0;
}