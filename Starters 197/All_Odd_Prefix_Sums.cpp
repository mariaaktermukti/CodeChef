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
        int odd_count = 0;
        for (int i = 0; i < N; i++) 
        {
            int x;
            cin >> x;
            if (x % 2 != 0) 
            {
                odd_count++;
            }
        }

        if (odd_count == 1)  cout << "Yes" << endl;     
        else cout << "No" << endl;  
    }

    return 0;
}
