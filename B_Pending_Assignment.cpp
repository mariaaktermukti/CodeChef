#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T; 

    while (T--) {
        int X, Y, Z;
        cin >> X >> Y >> Z; 

        int total_time_needed = X * Y;        
        int total_time_available = Z * 24 * 60; 

        if (total_time_needed <= total_time_available) {
            cout << "YES" << endl; 
        } else {
            cout << "NO" << endl; 
        }
    }

    return 0;
}
