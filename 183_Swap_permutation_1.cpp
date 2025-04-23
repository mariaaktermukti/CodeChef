#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
static const ull INF = 1000000000000000000ULL;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    const int MAXN = 1000;
    vector<ull> cat(MAXN+1,0);
    cat[0] = 1;
    for(int n = 1; n <= MAXN; n++){
        __int128 sum = 0;
        for(int i = 0; i < n; i++){
            sum += (__int128)cat[i] * cat[n-1-i];
            if(sum > INF) { sum = INF; break; }
        }
        cat[n] = (ull)sum;
    }

    int T;
    cin >> T;
    while(T--){
        int n;
        ull K;
        cin >> n >> K;
        if(n > MAXN) {
            cout << -1 << "\n";
            continue;
        }
        if(K > cat[n]){
            cout << -1 << "\n";
            continue;
        }
        vector<int> avail(n);
        iota(avail.begin(), avail.end(), 1);

        ull rem = K - 1;  
        vector<int> ans;
        ans.reserve(n);

        for(int len = n; len >= 1; len--){
            ull block = cat[len-1];
            ull idx = rem / block;
            if(idx >= (ull)len) idx = len-1; 
            ans.push_back(avail[idx]);
            avail.erase(avail.begin() + idx);
            rem %= block;
        }
        for(int i = 0; i < n; i++){
            cout << ans[i] << (i+1<n ? ' ' : '\n');
        }
    }
    return 0;
}
