#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) 
    {
        int N;
        ll H;
        cin >> N >> H;

        ll d1 = 0, d2 = 0;
        for (int i = 0; i < N; i++) 
        {
            int S;
            ll D;
            cin >> S >> D;
            if (S == 1) d1 = max(d1, D);
            else        d2 = max(d2, D);
        }

        if (d1 == 0 && d2 == 0) 
        {
            cout << "-1\n";
            continue;
        }

        if (d2 == 0) 
        {
            cout << ((H + d1 - 1) / d1) << "\n";
            continue;
        }
        if (d1 == 0) 
        {
            cout << ( (H + d2 - 1) / d2 ) * 2 << "\n";
            continue;
        }
        ll ans = LLONG_MAX;

        ans = min(ans, (H + d1 - 1) / d1);

        ans = min(ans, ((H + d2 - 1) / d2) * 2);
        ll cnt2 = H / d2;
        for (ll t2 = max(0LL, cnt2 - 1); t2 <= cnt2 + 1; t2++) 
        {
            ll done = t2 * d2;
            ll time = t2 * 2;
            if (done < H) 
            {
                ll rem = H - done;
                time += (rem + d1 - 1) / d1;
            }
            ans = min(ans, time);
        }

        cout << ans << "\n";
    }
    return 0;
}
