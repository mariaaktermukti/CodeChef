#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t, n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        vector<int> A(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> A[i];
        }
        int caketomake, maxProfit = 0;
        int idx = 0;
        while (idx < n)
        {
            caketomake = A[idx];
            int spend = A[idx] * 30 * n;
            int sum = 0;
            for (int i = 0; i < n; i++)
            {
                if (A[i] >= caketomake)
                    sum += caketomake * 50;
                else
                    sum += A[i] * 50;
            }

            maxProfit = max(maxProfit, sum - spend);
            idx++;
        }

        cout << maxProfit << endl;
    }
}