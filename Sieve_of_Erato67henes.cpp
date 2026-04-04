#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) 
    {
        int n;
        cin >> n;

        bool found = false;

        for (int i = 0; i < n; i++) 
        {
            int x;
            cin >> x;
            if (x == 67) 
            {
                found = true;
            }
        }

        if (found) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

    return 0;
}