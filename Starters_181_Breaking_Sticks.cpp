#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while(T--){
        int N;
        cin >> N;
        long long sum = 0;
        for(int i = 0, a; i < N; i++){
            cin >> a;
            sum += a;
        }
        cout << (sum - N) << "\n";
    }
    return 0;
}
