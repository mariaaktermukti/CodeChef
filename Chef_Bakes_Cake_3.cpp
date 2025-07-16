#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() 
{
    int T; 
    cin >> T;
    while (T--) 
    {
        int N; cin >> N;
        vector<int> A(N);
        int maxA = 0;
        for (int i = 0; i < N; ++i) 
        {
            cin >> A[i];
            maxA = max(maxA, A[i]);
        }
        int maxProfit = 0;
        for (int X = 0; X <= maxA; ++X) 
        {
            int sold = 0;
            for (int i = 0; i < N; ++i)
                sold += min(X, A[i]);
            int profit = 50 * sold - 30 * N * X;
            maxProfit = max(maxProfit, profit);
        }
        cout << maxProfit << endl;
    }
    return 0;
}