#include <bits/stdc++.h>
using namespace std;

int main() 
{
    int t;
    cin >> t;
    while(t--) 
    {
        int n;
        cin >> n;
        vector<int> v(n);         
        vector<int> position(n+1);
        int pos = 0;

        for(auto &i : v) 
        {
            cin >> i;
            position[i] = pos++;
        }

        vector<bool> removed(n, false); 
        long long ans = 0;

        for(int x = n; x >= 1; --x) 
        {
            int index = position[x];
            int left = 0, right = 0;

            for(int i = 0; i < index; ++i)
            {
                if(!removed[i]) 
                {
                    left++;
                }
            }

            for(int i = index+1; i < n; ++i)
            {
                if(!removed[i]) 
                {
                    right++;
                }
            }
            ans =ans + min(left, right);
            removed[index] = true;
        }

        cout << ans << endl;
    }
    return 0;
}
