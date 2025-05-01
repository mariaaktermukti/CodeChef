#include <bits/stdc++.h>
using namespace std;
using ll = long long;
static const int MOD = 998244353;

// fast exponentiation
ll modexp(ll a, ll e=MOD-2) {
    ll r=1;
    while(e){
        if(e&1) r=(r*a)%MOD;
        a=(a*a)%MOD;
        e>>=1;
    }
    return r;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; 
    cin >> T;
    while(T--){
        int N;
        cin >> N;
        vector<int> A(N);
        for(int i=0;i<N;i++) 
            cin >> A[i];

        // 1) Build frequency array for values in [0..N]
        vector<int> freq(N+1, 0);
        for(int x:A) 
            if(x<=N) 
                freq[x]++;

        // 2) Precompute 2^f for f up to N
        vector<ll> pow2(N+1,1);
        for(int i=1;i<=N;i++) 
            pow2[i] = (pow2[i-1]*2) % MOD;

        // 3) Compute P[i] = 2^{freq[i]} - 1, and invP[i] if freq[i]>0
        vector<ll> P(N+1), invP(N+1,0);
        for(int i=0;i<=N;i++){
            P[i] = (pow2[freq[i]] + MOD - 1) % MOD;
            if(freq[i]>0) 
                invP[i] = modexp(P[i]);
        }

        // 4) Build prefix arrays over i=0..N:
        vector<ll> prefixProd(N+2,1),   // ∏_{j<i, freq[j]>0} P[j]
                   prefixInvSum(N+2,0); // ∑_{j<i, freq[j]>0} invP[j]
        vector<int> zeroCount(N+2,0),
                    zeroXor  (N+2,0);
        for(int i=0;i<=N;i++){
            // carry over from i->i+1
            prefixProd[i+1]   = prefixProd[i];
            prefixInvSum[i+1] = prefixInvSum[i];
            zeroCount[i+1]    = zeroCount[i];
            zeroXor[i+1]      = zeroXor[i];

            if(freq[i]>0){
                prefixProd[i+1]   = (prefixProd[i+1] * P[i]) % MOD;
                prefixInvSum[i+1] = (prefixInvSum[i+1] + invP[i]) % MOD;
            } else {
                zeroCount[i+1]++;
                zeroXor[i+1] ^= i;
            }
        }

        // 5) Build suffix sums of freq: sufFreq[k] = sum_{i>k} freq[i]
        vector<int> sufFreq(N+2, 0);
        for(int i=N;i>=0;i--){
            sufFreq[i] = sufFreq[i+1] + freq[i];
        }

        // 6) For each k=1..N+1, compute count_k and accumulate k*count_k
        ll ans = 0;
        for(int k=1; k<=N+1; k++){
            int zc = zeroCount[k];  // zeros among freq[0..k-1]
            if(zc >= 2) 
                continue;           // no subsequences have SMEX=k

            ll waysHigh = modexp(2, sufFreq[k]);

            ll cntk = 0;
            if(zc == 0){
                // Case 1: all freq[0..k-1]>0
                ll Ak     = prefixProd[k];        // ∏ P[0..k-1]
                ll sumInv = prefixInvSum[k];      // ∑ invP[0..k-1]
                cntk = Ak * sumInv % MOD;
            } else {
                // Case 2: exactly one j missing in [0..k-1]
                cntk = prefixProd[k];             // product over i≠j0
            }

            cntk = (cntk * waysHigh) % MOD;
            ans  = (ans + ll(k) * cntk) % MOD;
        }

        // **Subtract the empty‐subsequence contribution (SMEX(empty)=1)**
        ans = (ans + MOD - 1) % MOD;

        cout << ans << "\n";
    }
    return 0;
}
