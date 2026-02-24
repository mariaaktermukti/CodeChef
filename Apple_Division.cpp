#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<ll> p(n);
    ll total = 0;
    for (int i = 0; i < n; i++) 
    {
        cin >> p[i];
        total += p[i];
    }

    ll best = LLONG_MAX;
    int limit = 1 << n;
    for (int mask = 0; mask < limit; mask++) 
    {
        ll sum = 0;
        for (int i = 0; i < n; i++) 
        {
            if (mask & (1 << i)) 
            {
                sum += p[i];
            }
        }
        ll diff = llabs(total - 2 * sum);
        best = min(best, diff);
    }

    cout << best << "\n";
    return 0;
}
