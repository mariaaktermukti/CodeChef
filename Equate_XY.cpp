#include <bits/stdc++.h>
using namespace std;

vector<long long> Divisor(long long n) 
{
    vector<long long> m;
    for (long long i = 1; i*i <= n; ++i) 
    {
        if (n%i == 0) 
        {
            m.push_back(i);
            if (i*i != n) 
            {
                m.push_back(n/i);
            }
        }
    }
    return m;
}

int main() 
{
    int T; 
    cin >> T;
    while (T--) 
    {
        long long X, Y, Z, C;
        cin >> X >> Y >> Z >> C;
        if (X == Y) 
        {
            cout << 0 << endl;
            continue;
        }
        long long res = 2*C;
        for (long long t : Divisor(X)) 
        {
            if (t%Y == 0) 
            {
                long long cost = C + llabs(Z-t);
                res = min(res, cost);
            }
        }
        for (long long t : Divisor(Y)) 
        {
            if (t%X == 0) 
            {
                long long cost = C + llabs(Z-t);
                res = min(res, cost);
            }
        }
        
        cout << res << endl;
    }
    return 0;
}
