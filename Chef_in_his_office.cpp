#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;
    while(T--) {
        int X, Y;
        cin >> X >> Y;
        int totalHours = 4 * X + Y;
        cout << totalHours << endl;
    }
    return 0;
}
