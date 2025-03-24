#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    cin >> T;
    
    while(T--)
    {
        long long N, X;
        cin >> N >> X;

        if(N % 2 == 0) 
        {
            cout << "YES" << "\n";
        } 
        else 
        {
            if(X % 2 == 1)
                cout << "YES" << "\n";
            else
                cout << "NO" << "\n";
        }
    }
    
    return 0;
}
