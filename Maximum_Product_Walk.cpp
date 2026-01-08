#include <bits/stdc++.h>
using namespace std;

static const long long MOD = 998244353;
static const long long MODM1 = MOD - 1;
static const long long NEG_INF = -(1LL << 60);

long long pow2(long long x)
{
    x %= MODM1;
    if (x < 0)
        x += MODM1;
    long long res = 1, base = 2;
    while (x)
    {
        if (x & 1)
            res = (res * base) % MOD;
        base = (base * base) % MOD;
        x >>= 1;
    }
    return res;
}

int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        int N;
        cin >> N;

        vector<long long> A(N);
        for (int i = 0; i < N; i++)
            cin >> A[i];

        vector<vector<int>> adj(N);
        for (int i = 0; i < N - 1; i++)
        {
            int u, v;
            cin >> u >> v;
            --u;
            --v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> parent(N, -1), order;
        order.reserve(N);
        queue<int> q;
        q.push(0);
        parent[0] = -2;

        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            order.push_back(u);
            for (int v : adj[u])
            {
                if (parent[v] == -1)
                {
                    parent[v] = u;
                    q.push(v);
                }
            }
        }

        vector<long long> dp_even(N, NEG_INF), dp_odd(N, NEG_INF);

        for (int i = N - 1; i >= 0; i--)
        {
            int u = order[i];
            long long w = llabs(A[u]);

            if (A[u] > 0)
                dp_even[u] = w;
            else
                dp_odd[u] = w;

            for (int v : adj[u])
            {
                if (parent[v] != u)
                    continue;

                long long ne = dp_even[u], no = dp_odd[u];

                if (dp_even[v] > NEG_INF)
                {
                    if (dp_even[u] > NEG_INF)
                        ne = max(ne, dp_even[u] + dp_even[v]);
                    if (dp_odd[u] > NEG_INF)
                        no = max(no, dp_odd[u] + dp_even[v]);
                }

                if (dp_odd[v] > NEG_INF)
                {
                    if (dp_even[u] > NEG_INF)
                        no = max(no, dp_even[u] + dp_odd[v]);
                    if (dp_odd[u] > NEG_INF)
                        ne = max(ne, dp_odd[u] + dp_odd[v]);
                }

                dp_even[u] = ne;
                dp_odd[u] = no;
            }
        }

        long long best_even = *max_element(dp_even.begin(), dp_even.end());
        long long best_odd = *max_element(dp_odd.begin(), dp_odd.end());

        long long ans;
        if (best_even > NEG_INF)
        {
            ans = pow2(best_even);
        }
        else
        {
            ans = pow2(best_odd);
            ans = (MOD - ans) % MOD;
        }

        cout << ans << "\n";
    }
    return 0;
}
