#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, cnt = 0;
        string s;
        cin >> n >> s;
        stack<char> st;
        for (auto i : s)
        {
            if (!st.empty() && st.top() != i)
            {
                st.pop();
                cnt++;
            }
            else
            {
                st.push(i);
            }
        }
        if (cnt % 2 == 0)
        {
            cout << "Ramos";
        }
        else
        {
            cout << "Zlatan";
        }
        cout << endl;
    }
}