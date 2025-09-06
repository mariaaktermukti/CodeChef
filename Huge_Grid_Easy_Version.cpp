#include <bits/stdc++.h>

using namespace std;
using ll = long long;
void s()
{
    int n;
    cin >> n;
    string str;
    cin >> str;
    vector<int> p(n);
    iota(p.begin(), p.end(), 0);
    auto red = [&](ll sm, int i)
    {
        if (str[i] == '0')
        {
            return sm;
        }
        return sm + ((i == 0 || i == n - 1) ? 2 : 3);
    };

    ll ans = accumulate(p.begin(), p.end(), 0LL, red);
    if (n == 1 && str[0] == '1')
    {
        ans = 1;
    }
    cout << ans << endl;
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