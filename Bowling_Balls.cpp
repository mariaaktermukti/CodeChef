#include <bits/stdc++.h>
using namespace std;

int main() 
{
    int T;
    cin >> T;
    while (T--) 
    {
        int N, X, Y;
        cin >> N >> X >> Y;
        vector<int> A(N);
        for (int i = 0; i < N; i++) 
        {
            cin >> A[i];
        }

        int count = 0;
        for (int w : A) 
        {
            if (w >= X && w <= Y) 
            {
                count++;
            }
        }

        cout << count << endl;
    }

    return 0;
}
