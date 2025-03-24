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
        int N;
        cin >> N;
        string s;
        cin >> s;
        
        for(int i = 0; i + 1 < N; i += 2)
        {
            swap(s[i], s[i+1]);
        }
        for (int i = 0; i < N; i++)
        {
            s[i] = 'z' - (s[i] - 'a');
        }
        
        cout << s << "\n";
    }
    return 0;
}
