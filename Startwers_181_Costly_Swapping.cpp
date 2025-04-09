#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
const int MOD = 998244353;
 
// We need factorials up to (2*N) and here N<=400, so we compute up to 800.
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int T;
    cin >> T;
    
    // Precompute factorials and inverse factorials up to maxVal = 800.
    int maxVal = 800;
    vector<ll> fact(maxVal+1), invFact(maxVal+1);
    fact[0] = 1;
    for (int i = 1; i <= maxVal; i++){
        fact[i] = (fact[i-1] * i) % MOD;
    }
    auto modexp = [&](ll base, ll exp) -> ll {
        ll res = 1;
        while(exp > 0){
            if(exp & 1) res = (res * base) % MOD;
            base = (base * base) % MOD;
            exp /= 2;
        }
        return res;
    };
    invFact[maxVal] = modexp(fact[maxVal], MOD-2);
    for (int i = maxVal; i > 0; i--){
        invFact[i-1] = (invFact[i] * i) % MOD;
    }
    auto nCr = [&](int n, int r) -> ll {
        if(r < 0 || r > n) return 0;
        return ((fact[n] * invFact[r]) % MOD * invFact[n-r]) % MOD;
    };
 
    // Process each test case.
    while(T--){
        int N;
        ll A, B, C, D;
        cin >> N >> A >> B >> C >> D;
 
        // Our total answer will be the sum over indices i, positions v and w as derived.
        // Note: v and w (with v < w) come from the chosen positions for the "i-th one"
        // in the sorted order of one positions in the two strings.
        //
        // When p_i = v and r_i = w, the cost contribution is (w-v)*min(B,C).
        // When p_i = w and r_i = v, the cost is (w-v)*min(A,D).
        // Their count (over all pairs of m-element subsets, summed over
        // all m that allow an i-th position) is given by the combinatorial factors.
 
        ll ans = 0;
        ll costUp = min(B, C) % MOD;  // when the left index (p_i) is the smaller one
        ll costDown = min(A, D) % MOD; // when the left index comes from the larger number (i.e. p_i > r_i)
 
        // Loop over v and w:
        // We use v for the smaller of the two numbers (v < w).
        // For each possible order index i, valid choices are i from 1 to v.
        for (int v = 1; v <= N; v++){
            for (int w = v+1; w <= N; w++){
                ll diff = (w - v) % MOD;  // (w - v)
                // Sum over the order index i.
                for (int i = 1; i <= v; i++){
                    // When p_i = v and r_i = w:
                    ll ways1 = nCr(v - 1, i - 1);            // ways to choose the first i-1 positions in the subset (<= v)
                    ways1 = (ways1 * nCr(w - 1, i - 1)) % MOD; // ways for r's i-th element being w
                    ways1 = (ways1 * nCr(2 * N - v - w, N - v)) % MOD; // ways to choose the remaining positions in X and Y
                    ll term1 = (diff * costUp) % MOD;
                    term1 = (term1 * ways1) % MOD;
 
                    // When p_i = w and r_i = v:
                    ll ways2 = nCr(v - 1, i - 1);            // For the smaller position in r
                    ways2 = (ways2 * nCr(w - 1, i - 1)) % MOD; // For the larger position in p
                    ways2 = (ways2 * nCr(2 * N - v - w, N - w)) % MOD; // ways to choose the remaining positions
                    ll term2 = (diff * costDown) % MOD;
                    term2 = (term2 * ways2) % MOD;
 
                    ans = (ans + term1 + term2) % MOD;
                }
            }
        }
 
        cout << ans % MOD << "\n";
    }
    return 0;
}
