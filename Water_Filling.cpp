#include <iostream>
using namespace std;

int main() 
{
    int T;
    cin >> T;  
    
    while (T--) 
    {
        int B1, B2, B3;
        cin >> B1 >> B2 >> B3;  
        
        int emptyCount = (B1 == 0) + (B2 == 0) + (B3 == 0);
        
        if (emptyCount >= 2) 
        {
            cout << "Water filling time" << endl;
        } 
        else 
        {
            cout << "Not now" << endl;
        }
    }
    
    return 0;
}
