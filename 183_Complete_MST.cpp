#include <bits/stdc++.h>
using namespace std;
using int64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int64 N, M;
        cin >> N >> M;
        int64 total = N * (N - 1) / 2;
        int64 Z = total - M; 
        
        int64 c_min = N - Z;
        if (c_min < 1) c_min = 1;
        int64 W_min = c_min - 1;

        int64 k;
        if (Z == 0) {
            k = 1;
        } else {
            long double D = sqrtl((long double)1 + 8 * (long double)Z);
            k = ceill((1 + D) / 2.0L);
            while (k * (k - 1) / 2 < Z) ++k;
            while ((k - 1) * (k - 2) / 2 >= Z) --k;
        }
        int64 c_max = N - k + 1;
        int64 W_max = c_max - 1;
    
        if (W_max < W_min) {
            cout << 0 << '\n';
        } else {
            int64 cnt = W_max - W_min + 1;
            __int128 s = (__int128)cnt * (W_min + W_max) / 2;
            cout << (int64)s << '\n';
        }
    }
    return 0;
}