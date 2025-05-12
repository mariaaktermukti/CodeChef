#include <bits/stdc++.h>
#define ll long long int
using namespace std;

vector<int> allPali;
void precompute()
{
    for (int i = 0; i < 32786; i++)
    {
        string s = to_string(i);
        string temp = s;
        reverse(s.begin(), s.end());
        if (temp == s)
        {
            allPali.push_back(i);
        }
    }
}

void solve()
{
    ll n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    unordered_map<int, int> x;
    ll ans = 0;
    for (auto ele : v)
    {
        ++x[ele];
        for (auto pali : allPali)
        {
            ans += x[ele ^ pali];
        }
    }
    cout << ans << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    precompute();
    int t;
    cin >> t;

    while (t-- > 0)
    {
        solve();
    }
    return 0;
}
