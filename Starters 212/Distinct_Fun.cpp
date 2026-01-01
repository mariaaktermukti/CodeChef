#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll t;
    cin >> t;
    while (t-- > 0)
    {
        ll n;
        cin >> n;
        vector<ll> a(n);
        set<ll> s;
        for (ll i = 0; i < n; i++)
        {
            cin >> a[i];
            s.insert(a[i]);
        }
        if (s.size() == n)
        {
            cout << 0 << endl;
            continue;
        }
        s.clear();
        int i = 0;
        ll cnt = 0;
        while (i < n && s.find(a[i]) == s.end())
        {
            s.insert(a[i]);
            i++;
        }
        while (i < n)
        {
            set<ll> sub;
            while (i < n && sub.find(a[i]) == sub.end())
            {
                sub.insert(a[i]);
                i++;
            }
            cnt++;
        }

        cout << cnt << endl;
    }
}