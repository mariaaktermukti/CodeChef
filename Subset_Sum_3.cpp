#include <bits/stdc++.h>
using namespace std;

int main() 
{
    int T;
    cin >> T;
    while (T--) 
    {
        int N;
        cin >> N;
        vector<int> A(N);
        for (int i = 0; i < N; i++) 
        {
            cin >> A[i];
            A[i] %= 3;  
        }

        array<bool,3> dp = {false, false, false};

        for (int x : A) 
        {
            array<bool,3> next = dp;
            next[x] = true;
            for (int r = 0; r < 3; r++) 
            {
                if (dp[r]) 
                {
                    next[(r + x) % 3] = true;
                }
            }
            dp = next;
        }
        cout << (dp[0] ? "Yes\n" : "No\n");
    }
    return 0;
}
