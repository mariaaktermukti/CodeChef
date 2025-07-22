#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <functional>

void solve() 
{
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) 
    {
        std::cin >> a[i];
    }

    std::sort(a.begin(), a.end(), std::greater<int>());

    std::vector<long long> max_A_sum(n + 1, 0);
    for (int i = 0; i < n; ++i) 
    {
        max_A_sum[i + 1] = max_A_sum[i] + a[i];
    }
    
    auto sum_upto = [](long long k) -> long long 
    {
        if (k < 0) return 0;
        return k * (k + 1) / 2;
    };

    std::vector<long long> ans(2 * n + 1, 0);

    for (int j = 0; j <= n; ++j) 
    {
        for (int p = 0; p <= j; ++p) 
        {
            int cost = j + p;
            if (cost > 0 && cost <= 2 * n) 
            {
                long long bonus = sum_upto(j - 1) - sum_upto(j - p - 1);
                long long current_sum = max_A_sum[j] + bonus;
                ans[cost] = std::max(ans[cost], current_sum);
            }
        }
    }
    

    for (int k = 1; k <= 2 * n; ++k) 
    {
        ans[k] = std::max(ans[k], ans[k - 1]);
    }

    for (int k = 1; k <= 2 * n; ++k) 
    {
        std::cout << ans[k] << (k == 2 * n ? "" : " ");
    }
    std::cout << "\n";
}

int main() 
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    std::cin >> t;
    while (t--) 
    {
        solve();
    }
    return 0;
}