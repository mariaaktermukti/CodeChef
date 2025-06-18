#include <iostream>
using namespace std;

int GCD(int x, int y) 
{
    while (y != 0) 
    {
        int temp = y;
        y = x % y;
        x = temp;
    }
    return x;
}

int main() 
{
    int T;
    cin>>T;

    while (T--) 
    {
        int X, Y;
        cin >>X>>Y;

        if (GCD(X, Y) != 1) 
        {
            cout << 0 << endl;
        } 
        else if (GCD(X + 1, Y) != 1 || GCD(X, Y + 1) != 1) 
        {
            cout << 1 << endl;
        } 
        else 
        {
            cout << 2 << endl;
        }
    }
    return 0;
}