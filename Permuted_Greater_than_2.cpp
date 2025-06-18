#include <bits/stdc++.h>
using namespace std;

int main() {
    int T; 
    cin >> T;
    while (T--) 
    {
        int X, Y, Z;
        cin >> X >> Y >> Z;

        if (X == 0) 
        {
            cout << "Yes" << endl;
        } 
        else if (Y == 0) 
        {
            if (Z >= X - 1) cout << "Yes" << endl;
            else cout << "No" << endl;
        } 
        else 
        {
            if (Z >= X) cout << "Yes" << endl;
            else cout << "No" << endl;
        }
    }

    return 0;
}
