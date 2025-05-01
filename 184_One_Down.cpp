#include <bits/stdc++.h>
using namespace std;

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int TC;
    cin >> TC;
    while (TC--) 
    {
        int N;
        string S, T;
        cin >> N >> S >> T;

        int cntS = 0, cntT = 0;
        for (char c : S) if (c == '1') cntS++;
        for (char c : T) if (c == '1') cntT++;
        bool ok = true;
        for (int i = 0; i < N; i++) 
        {
            if (T[i] == '1' && S[i] == '0') 
            {
                ok = false;
                break;
            }
        }
        if (ok) 
        {
            if (cntS < cntT || ((cntS - cntT) % 2 != 0)) 
            {
                ok = false;
            }
        }

        cout << (ok ? "Yes\n" : "No\n");
    }

    return 0;
}
