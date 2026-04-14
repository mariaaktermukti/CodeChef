#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, q;
        cin >> n >> q;
        vector<ll> L(n), R(n), P(n, -1);
        for (int i = 0; i < n; i++)
            P[i] = i;
        for (int i = 0; i < n; i++)
        {
            cin >> L[i] >> R[i];
            L[i]--;
            R[i]--;
            if (L[i] != -1)
            {
                P[L[i]] = i;
                P[R[i]] = i;
            }
        }
        vector<ll> dp(n);
        vector<array<int, 20>> lift(n);
        auto dfs1 = [&](auto dfs1, int x) -> ll
        {
            if (L[x] == -1)
                return dp[x] = 1;
            else
                return dp[x] = (dfs1(dfs1, L[x]) + dfs1(dfs1, R[x]) + 3);
        };
        dfs1(dfs1, 0);
        vector<ll> euler, tin(n);
        auto dfs2 = [&](auto dfs2, int x) -> void
        {
            tin[x] = euler.size();
            lift[x][0] = P[x];
            for (int j = 1; j < 20; j++)
            {
                lift[x][j] = lift[lift[x][j - 1]][j - 1];
            }
            if (L[x] == -1)
            {
                euler.push_back(x);
                return;
            }
            else
            {
                dp[L[x]] = (dp[L[x]] + dp[x]);
                dp[R[x]] = (dp[R[x]] + dp[x]);
                euler.push_back(x);
                dfs2(dfs2, L[x]);
                euler.push_back(x);
                dfs2(dfs2, R[x]);
                euler.push_back(x);
            }
        };
        dfs2(dfs2, 0);
        while (q--)
        {
            ll v, k;
            cin >> v >> k;
            v--;
            ll w = v;
            for (int j = 19; j >= 0; j--)
            {
                if (dp[v] - dp[lift[w][j]] <= k)
                    w = lift[w][j];
            }
            k -= dp[v] - dp[w];
            cout << euler[tin[w] + k] + 1 << " \n"[q == 0];
        }
    }
}