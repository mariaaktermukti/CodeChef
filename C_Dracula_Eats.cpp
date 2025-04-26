#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T; 

    while (T--) {
        int N;
        cin >> N; 

        int tuesdays = (N + 5) / 7;

        cout << tuesdays << endl;
    }

    return 0;
}
