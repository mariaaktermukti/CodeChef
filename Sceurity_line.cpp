#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) 
    {
        int N;
        cin >> N;
        vector<int> A(N+1);
        for(int i = 1; i <= N; ++i) 
        {
            cin >> A[i];
        }
        int minimum_numof_sec = A[1];
        for(int j = 2; j <= N; ++j) 
        {
            int x = j - 1;                  
            int total_wait = A[j] + 1;            
            int timeJ = max(x, total_wait);
            minimum_numof_sec = min(minimum_numof_sec, timeJ);
        }
        
        cout << minimum_numof_sec << endl;
    }
    return 0;
}
