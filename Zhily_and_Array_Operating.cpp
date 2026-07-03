#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        vector<long long> a(n + 1);
        for (int i = 1; i <= n; i++)
            cin >> a[i];

        for (int i = n - 1; i >= 1; i--)
        {
            if (a[i + 1] > 0)
            {
                a[i] += a[i + 1];
            }
        }

        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            if (a[i] > 0)
                ans++;
        }
        cout << ans << endl;
    }
    return 0;
}