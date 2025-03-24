#include <iostream>
#include <string>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    cin >> T;
    
    while(T--)
    {
        string s1, s2;
        cin >> s1 >> s2;
        int n = s1.size();
        
        int minDiff = 0, maxDiff = 0;
        for(int i = 0; i < n; i++)
        {
            if(s1[i]=='?' || s2[i]=='?')
            {
                maxDiff++;
            }
            else
            {
                if(s1[i] != s2[i]){
                    minDiff++;
                    maxDiff++;
                }
            }
        }
        
        cout << minDiff << " " << maxDiff << "\n";
    }
    
    return 0;
}
