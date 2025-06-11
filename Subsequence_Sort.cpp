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
        int N;
        cin >> N;
        vector<ll> A(N);
        for(int i = 0; i < N; i++)
            cin >> A[i];
        bool sorted = true;
        for(int i = 1; i < N; i++)
        {
            if(A[i] < A[i-1])
            {
                sorted = false;
                break;
            }
        }
        if(sorted)
        {
            cout << 0 << "\n";
            continue;
        }
        ll answer = -1;
        for(int m = 1; m <= 31; m++)
        {
            ll B = ((1LL << m) - 1);
            ll prev = 0;   
            bool ok = true;
            for(int i = 0; i < N; i++)
            {
                ll low  = A[i];
                ll high = A[i] | B;
                if(high < prev)
                {
                    ok = false;
                    break;
                }
                prev = max(prev, low);
            }
            if(ok)
            {
                answer = (1LL << (m-1));
                break;
            }
        }
        cout << answer << "\n";
    }
    return 0;
}
