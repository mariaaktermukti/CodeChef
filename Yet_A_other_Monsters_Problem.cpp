#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int T;
    cin >> T;
    while (T--) 
    {
        int N;
        cin >> N;
        vector<ll> A(N);
        for (int i = 0; i < N; i++) 
        {
            cin >> A[i];
        }
        vector<int> c(N+2, 0);
        for (ll x : A) 
        {
            if (x <= N) 
            {
                c[x]++;
            } 
            else 
            {
                c[N+1]++;
            }
        }
        vector<int> S(N+1);
        vector<int> suff(N+2, 0);
        suff[N+1] = c[N+1];
        for (int k = N; k >= 1; k--) 
        {
            suff[k] = suff[k+1] + c[k];
        }
        S[0] = N;  
        for (int b = 1; b <= N; b++) 
        {
            S[b] = suff[b+1];
        }
        ll ans = LLONG_MAX;
        for (int b = 0; b <= N; b++) 
        {
            ans = min(ans, ll(b) + ll(S[b]));
        }

        cout << ans << "\n";
    }
    return 0;
}
