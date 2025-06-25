#include <bits/stdc++.h>
using namespace std;

bool checkingGood(const vector<int> &B)
{
    int sum = 0;
    for (int x : B)
    {
        sum += x;
        if (sum % 3 == 0)
        {
            return false;
        }  
    }
    return true;
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int N;
        cin >> N;
        vector<int> A(N);
        for (int i = 0; i < N; ++i)
            cin >> A[i];

        if (checkingGood(A))
        {
            cout << "Yes" << endl;
            continue;
        }

        bool flag = false;
        for (int k = 1; k <= N; ++k)
        {
            int sum = 0;
            for (int i = 0; i < k; ++i)
            {
                sum = sum + A[k - 1 - i];
                if (sum % 3 == 0)
                {
                    sum = INT_MIN;
                    break;
                }
            }
            if (sum == INT_MIN)
            {
                continue;
            }
            for (int i = k; i < N; ++i)
            {
                sum = sum + A[i];
                if (sum % 3 == 0)
                {
                    sum = INT_MIN;
                    break;
                }
            }
            if (sum != INT_MIN)
            {
                flag = true;
                break;
            }
        }

        if (flag)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}
