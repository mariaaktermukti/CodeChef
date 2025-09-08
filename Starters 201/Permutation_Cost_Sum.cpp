#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int MOD = 998244353;
vector<int> par, sz;

int find(int i)
{
    if (par[i] == i)
        return i;
    return par[i] = find(par[i]);
}

void unite(int i, int j)
{
    int root_i = find(i);
    int root_j = find(j);
    if (root_i != root_j)
    {
        if (sz[root_i] < sz[root_j])
            swap(root_i, root_j);
        par[root_j] = root_i;
        sz[root_i] += sz[root_j];
    }
}
ll power(ll b, ll e)
{
    ll res = 1;
    b %= MOD;
    while (e > 0)
    {
        if (e % 2 == 1)
            res = (res * b) % MOD;
        b = (b * b) % MOD;
        e /= 2;
    }
    return res;
}
ll inv(ll n) { return power(n, MOD - 2); }
ll calc_sum(int n, int c1, int c2)
{
    ll total = 0;
    ll n_ll = n;
    ll inv2 = inv(2);
    ll c1m = c1 % MOD, c2m = c2 % MOD;
    for (ll i = 1; i <= n_ll; ++i)
    {
        ll J = min(n_ll, (ll)((long double)c1 * i / c2));
        ll jm = J % MOD;
        ll p1 = (jm * (jm + 1)) % MOD;
        p1 = (p1 * inv2) % MOD;
        p1 = (p1 * c2m) % MOD;
        ll p2 = (c1m * (i % MOD)) % MOD;
        p2 = (p2 * ((n_ll - J % MOD + MOD) % MOD)) % MOD;
        total = (total + p1 + p2) % MOD;
    }
    return total;
}
void s()
{
    int n;
    cin >> n;
    vector<int> p(n);
    par.resize(n);
    sz.assign(n, 1);
    iota(par.begin(), par.end(), 0);
    for (int i = 0; i < n; ++i)
    {
        cin >> p[i];
        p[i]--;
        unite(i, p[i]);
    }
    map<int, int> c_cnt;
    for (int i = 0; i < n; ++i)
    {
        if (par[i] == i && sz[i] > 1)
        {
            c_cnt[sz[i]]++;
        }
    }
    ll total_ans = 0;
    for (auto const &[len, freq] : c_cnt)
    {
        ll c1 = len;
        ll c2 = len - 1;
        ll c_sum = calc_sum(n, c1, c2);
        total_ans = (total_ans + (ll)freq * c_sum) % MOD;
    }
    cout << total_ans << endl;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        s();
    }
}