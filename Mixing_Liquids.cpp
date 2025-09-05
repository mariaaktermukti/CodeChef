#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long a, b;
        cin >> a >> b;
        int c = 3 * min(a, b / 2);
        cout << c << endl;
    }
    return 0;
}