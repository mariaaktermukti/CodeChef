#include <iostream>
#include <vector>
using namespace std;

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) 
    {
        int N;
        cin >> N;
        vector<int> A(N);
        int total_sum = 0;
        int count_3 = 0;
        for (int i = 0; i < N; ++i) 
        {
            cin >> A[i];
            total_sum += A[i];
            if (A[i] == 3) {
                count_3++;
            }
        }
        int ans = 0;
        for (int i = 0; i < N; ++i) 
        {
            if (A[i] == 0) 
            {
                continue;
            }
            int new_sum = total_sum - 1;
            int new_count_3 = count_3 - (A[i] == 3 ? 1 : 0);
            if (new_sum % 2 == 0 && new_count_3 == 0) 
            {
                ans++;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}