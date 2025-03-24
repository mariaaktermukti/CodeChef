#include <iostream>
using namespace std;

void solve() 
{
    int A, B;
    cin >> A >> B;
    
    int turn = 1;
    while (true) 
    {
        if (turn % 2 == 1) 
        { 
            if (A < turn) 
            {
                cout << "Bob" << endl;
                return;
            }
            A -= turn;
        } 
        else 
        { 
            if (B < turn) 
            {
                cout << "Limak" << endl;
                return;
            }
            B -= turn;
        }
        turn++;
    }
}

int main() 
{
    int T;
    cin >> T;
    while (T--) 
    {
        solve();
    }
    return 0;
}