#include <bits/stdc++.h>
using namespace std;

#define MOD 998244353
#define int long long

int solve(vector<int>& B) {
    int N = B.size();
    vector<int> left(N), right(N);
    for (int i = 0; i < N; ++i) {
        int k = min(i + 1, N - i);
        left[i] = i - k + 1;
        right[i] = i + k - 1;
    }

    // Check consistency of max ranges
    vector<int> maxval(N, -1);
    for (int i = 0; i < N; ++i) {
        for (int j = left[i]; j <= right[i]; ++j) {
            if (j < 0 || j >= N) continue;
            maxval[j] = max(maxval[j], B[i]);
        }
    }

    for (int i = 0; i < N; ++i) {
        if (maxval[i] != B[i]) return 0;
    }

    // Count number of ways to assign values to A
    function<int(int, int)> dfs = [&](int l, int r) -> int {
        if (l > r) return 1;
        int mx = -1, idx = -1;
        for (int i = l; i <= r; ++i) {
            if (B[i] > mx) {
                mx = B[i];
                idx = i;
            }
        }
        int left_ways = dfs(l, idx - 1);
        int right_ways = dfs(idx + 1, r);
        return (left_ways * right_ways) % MOD;
    };

    return dfs(0, N - 1);
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<int> B(N);
        for (int i = 0; i < N; ++i) cin >> B[i];
        cout << solve(B) << '\n';
    }

    return 0;
}
