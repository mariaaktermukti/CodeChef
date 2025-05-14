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
        ll X, Y;
        cin >> N >> X >> Y;
        vector<ll> A(N);
        for (int i = 0; i < N; i++) 
            cin >> A[i];

        vector<int> goodKs;

        for (int K = 1; K <= N; K++)
        {
            vector<ll> B(A.begin(), A.begin() + K);
            bool ok = false;
            for (int i = 0; i < K && !ok; i++)
            {
                ll cur = X % B[i];
                vector<ll> rest;
                rest.reserve(K-1);
                for (int j = 0; j < K; j++)
                {
                    if (j == i) continue;
                    rest.push_back(B[j]);
                }
                sort(rest.begin(), rest.end(), greater<ll>());

                for (ll b : rest)
                {
                    if (cur >= b) 
                        cur %= b;
                }

                if (cur == Y) 
                {
                    ok = true;
                }
            }

            if (ok) 
                goodKs.push_back(K);
        }

        cout << goodKs.size() << "\n";
        if (!goodKs.empty())
        {
            for (int k : goodKs) 
                cout << k << " ";
            cout << "\n";
        } 
        else 
        {
            cout << "\n";
        }
    }

    return 0;
}
