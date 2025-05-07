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
        cin >> N;
        vector<ll> A(2*N);
        for (ll &x : A) cin >> x;

        priority_queue<ll, vector<ll>, greater<ll>> H;
        for (int i = 0; i < 2*N; i++) 
        {
            H.push(A[i]);
            int keep = (i+2)/2; 
            if ((int)H.size() > keep) 
            {
                H.pop();
            }
        }
        ll ans = 0;
        while (!H.empty()) 
        {
            ans += H.top();
            H.pop();
        }
        cout << ans << "\n";
    }
    return 0;
}
