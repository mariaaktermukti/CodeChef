#include <iostream>
using namespace std;

int main() 
{
    int T;
    cin >> T;  
    while (T--) 
    {
        int X, Y;
        cin >> X >> Y; 
        
        int totalCoins = X * Y;
        
        int bags = totalCoins / 100;

        cout << bags << endl;
    }
    return 0;
}
