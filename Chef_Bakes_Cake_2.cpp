#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int N, count = 0;
        cin >> N;
        vector<int> A(N);
        vector<int> B(N);
        for (int i = 0; i < N; i++)
        {
            cin >> A[i];
        }
        for (int i = 0; i < N; i++)
        {
            cin >> B[i];
        }
        for (int i = 0; i < N; i++)
        {
            if (A[i] > B[i])
                count += A[i] - B[i];
        }
        cout << count << endl;
    }
    return 0;
}