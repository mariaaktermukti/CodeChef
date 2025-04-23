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
        vector<int> A(N);
        for (int &x : A) {
            cin >> x;
        }

        int mn = *min_element(A.begin(), A.end());
        int mx = *max_element(A.begin(), A.end());
        int goodCount = max(0, mx - mn - 1);
        cout << goodCount << "\n";
    }

    return 0;
}
