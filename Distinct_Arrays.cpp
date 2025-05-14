#include <bits/stdc++.h>
using namespace std;
static const int MOD = 998244353;

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
        vector<long long> A(N);
        for (int i = 0; i < N; i++) 
        {
            cin >> A[i];
        }

        sort(A.begin(), A.end());

        long long ans = 1;
        for (int i = 0; i < N; i++) 
        {
            long long choices = A[i] - i;
            if (choices <= 0) 
            {
                ans = 0;
                break;
            }
            ans = ans * (choices % MOD) % MOD;
        }

        cout << ans << "\n";
    }
    return 0;
}
