#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    const int P = 999999937;  

    int T;
    cin >> T;
    while(T--){
        ll N, K;
        cin >> N >> K;

        if (K < N-1) {
            cout << -1 << "\n";
            continue;
        }

        ll D = K - (N - 2);

        if (N == 2) {
            cout << D << " " << 2*D << "\n";
            continue;
        }

        cout << D << " " << 2*D;
        for (int i = 3; i <= N; i++) {
            cout << " " << (P - (i - 3));
        }
        cout << "\n";
    }

    return 0;
}
