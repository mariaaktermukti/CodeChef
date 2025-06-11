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
        ll X;
        cin >> N >> X;
        vector<ll> A(N), B(N);
        for(int i = 0; i < N; i++) cin >> A[i];
        for(int i = 0; i < N; i++) cin >> B[i];

        priority_queue<ll> pq;
        int cnt = 0;

        for(int i = 0; i < N; i++)
        {
            while(cnt > 0 && cnt > X - A[i])
            {
                cnt--;
                pq.pop();
            }
            if(X - cnt >= B[i])
            {
                pq.push(B[i]);
                cnt++;
            }
        }
        cout << cnt << "\n";
    }

    return 0;
}
