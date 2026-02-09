#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        long long ans = 0;
        int count[11][11];
        memset(count, 0, sizeof(count));

        for (int i = 0; i < n; ++i) {
            string s;
            cin >> s;
            int a = s[0] - 'a';
            int b = s[1] - 'a';
            for (int j = 0; j < 11; ++j) {
                if (j != a) {
                    ans += count[j][b];
                }
            }
            for (int j = 0; j < 11; ++j) {
                if (j != b) {
                    ans += count[a][j];
                }
            }
            count[a][b]++;
        }

        cout << ans << '\n';
    }
    return 0;
}
