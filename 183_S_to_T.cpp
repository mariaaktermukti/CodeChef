#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int TT;
    cin >> TT;
    while (TT--) {
        int N;
        cin >> N;
        string S, T;
        cin >> S >> T;

        int firstOne = -1;
        for (int i = 0; i < N; ++i) {
            if (S[i] == '1') {
                firstOne = i;
                break;
            }
        }
        vector<int> ops;
        bool possible = true;

        if (firstOne == -1) {
            for (char c : T) if (c == '1') possible = false;
            if (!possible) cout << -1 << '\n';
            else cout << 0 << '\n';
            continue;
        }

        for (int i = 0; i < firstOne; ++i) {
            if (T[i] != '0') possible = false;
        }
        if (T[firstOne] != '1') possible = false;
        if (!possible) {
            cout << -1 << '\n';
            continue;
        }
        for (int i = firstOne + 1; i < N; ++i) {
            if (S[i] == '0') {
                ops.push_back(i); 
                S[i] = '1';
            }
        }
        for (int i = N - 1; i > firstOne; --i) {
            if (T[i] == '0') {
                ops.push_back(i);
                S[i] = '0';
            }
        }
        cout << ops.size() << '\n';
        if (!ops.empty()) {
            for (int idx : ops) cout << idx << ' ';
            cout << '\n';
        }
    }
    return 0;
}