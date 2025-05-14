#include <bits/stdc++.h>
using namespace std;

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) 
    {
        long long N, M, A, B;
        cin >> N >> M >> A >> B;
        long long num = M - A * N;
        long long den = B - A;
        if (den > 0 && num % den == 0) 
        {
            long long y = num / den;
            if (0 <= y && y <= N) 
            {
                cout << "Yes\n";
                continue;
            }
        }
        cout << "No\n";
    }
    return 0;
}
