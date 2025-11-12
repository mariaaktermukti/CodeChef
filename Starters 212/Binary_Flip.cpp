#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        string s;
        cin >> n >> s;

        int cnt00 = 0, cnt11 = 0;
        for(int i = 0; i < n-1; ++i) 
        {
            if(s[i]=='0' && s[i+1]=='0') 
            {
                cnt00++;
            }
            if(s[i]=='1' && s[i+1]=='1')
            {
                cnt11++;
            }
        }

        int toggle  = 0;
        if(cnt00 > cnt11) 
        {
            toggle  = (cnt00 - cnt11 + 1) / 2;
        }

        cout << toggle << endl;
    }

    return 0;
}
