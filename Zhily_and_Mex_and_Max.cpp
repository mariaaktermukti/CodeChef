#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        int n;
        cin >> n;

        vector<int> a(n);
        for (int &x : a) cin >> x;
        
        sort(a.begin(), a.end());

        vector<int> b;
        b.push_back(a.back());

        vector<int> dup;

        for (int i = 0; i < n - 1; i++)
        {
            if (i == 0 || a[i] != a[i - 1]) b.push_back(a[i]);
            else dup.push_back(a[i]);      
        }

        for (int x : dup)
        {
            b.push_back(x);
        }
            
        map<int, int> cnt;
        int mex = 0;
        int mx = 0;
        ll ans = 0;

        for (int x : b)
        {
            cnt[x]++;
            mx = max(mx, x);

            while (cnt[mex])
            {
                mex++;
            }
            ans += 1LL * mx + mex;
        }

        cout << ans << endl;
    }

    return 0;
}