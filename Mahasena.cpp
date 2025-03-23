#include <iostream>
using namespace std;

int main() 
{
    int N;
    cin >> N;  
    int countEven = 0, countOdd = 0;
    
    for (int i = 0; i < N; i++) 
    {
        int weapons;
        cin >> weapons;
        
        if (weapons % 2 == 0) 
        {
            countEven++; 
        } 
        else 
        {
            countOdd++;   
        }
    }

    if (countEven > countOdd) 
    {
        cout << "READY FOR BATTLE" << endl;
    } 
    else 
    {
        cout << "NOT READY" << endl;
    }

    return 0;
}
