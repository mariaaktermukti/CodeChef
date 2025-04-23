#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<int> P(N);
        for (int i = 0; i < N; i++) cin >> P[i];

        vector<int> pos(N+1);
        for (int i = 0; i < N; i++) pos[P[i]] = i;

        for (int i = 1; i <= N; i++) {
            int idx = pos[i];
            if (idx > 0 && P[idx-1] > P[idx]) {
                swap(P[idx-1], P[idx]);
                pos[P[idx]] = idx;
                pos[P[idx-1]] = idx-1;
            }
        }

        for (int i = 0; i < N; i++) {
            cout << P[i] << (i+1<N ? ' ' : '\n');
        }
    }
    return 0;
}
