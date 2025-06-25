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
        int count1 = 0, count2 = 0;
        for (int i = 0; i < N; ++i) 
        {
            int x;
            cin >> x;
            if (x == 1) 
            {
                count1++;
            }
            else if (x == 2) 
            {
                count2++;  
            }
        }
        
        int operation_conv_1 = count2;
        int operation_into_2;
        if (count1 % 2 == 0) 
        {
            operation_into_2 = count1 / 2;
        } 
        else 
        {
            operation_into_2 = INT_MAX;  
        }

        int result = min(operation_conv_1, operation_into_2);
        cout << result << endl;
    }
    return 0;
}
