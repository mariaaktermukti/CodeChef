#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while(T--){
        int N;
        string S;
        cin >> N >> S;

        long long zeros = 0, ones = 0;
        int k = 0; 
        for(int i = 0; i < N; i++){
            if (S[i] == '0') zeros++;
            else             ones++;
            if (zeros == ones) 
                ++k;
        }
        unsigned long long ans = 1;
        ans <<= k;  

        cout << ans << "\n";
    }
    return 0;
}
