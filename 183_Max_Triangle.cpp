#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        long long N;
        cin >> N;
    
        if (N > 3) {
            long long perimeter = N + (N - 1) + (N - 2);
            cout << perimeter << '\n';
        } else {
            cout << -1 << '\n';
        }
    }

    return 0;
}
