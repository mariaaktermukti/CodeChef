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
        vector<int> A(5);
        for (int i = 0; i < 5; i++) 
        {
            cin >> A[i];
        }
        int sum = accumulate(A.begin(), A.end(), 0);
        if (sum >= 35) 
        {
            cout << 0 << '\n';
            continue;
        }
        sort(A.begin(), A.end());
        int coins = 0;
        for (int i = 0; i < 5 && sum < 35; i++) 
        {
            int gain = 10 - A[i];
            sum += gain;
            coins += 100;
        }
        cout << coins << '\n';
    }

    return 0;
}
