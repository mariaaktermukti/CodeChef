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
        int min_draws = -1;
        for (int d = 0; d <= min(X, Y); ++d) 
        {
            if ((X - d) % 3 == 0 && (Y - d) % 3 == 0) 
            {
                min_draws = d;
                break;
            }
        }
        cout << min_draws << endl;
    }
    return 0;
}
