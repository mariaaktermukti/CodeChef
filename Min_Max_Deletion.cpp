#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while(T--)
    {
        int N, Q;
        cin >> N >> Q;
        vector<ll> A(N+2, 0);
        for(int i = 1; i <= N; i++)
        {
            cin >> A[i];
        }
        ll total = 0;
        for(int i = 1; i < N; i++)
        {
            total += min(A[i], A[i+1]);
        }
        while(Q--)
        {
            int idx;
            ll X;
            cin >> idx >> X;
            if(idx > 1)
            {
                total -= min(A[idx-1], A[idx]);
            }
            if(idx < N)
            {
                total -= min(A[idx], A[idx+1]);
            }
            A[idx] = X;
            if(idx > 1)
            {
                total += min(A[idx-1], A[idx]);
            }
            if(idx < N)
            {
                total += min(A[idx], A[idx+1]);
            }
            cout << total << "\n";
        }
    }
    return 0;
}
