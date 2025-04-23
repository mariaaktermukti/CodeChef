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
        vector<int> P(N+1);
        for(int i = 1; i <= N; i++){
            cin >> P[i];
        }
        if(P[1] != 1 && P[N] != N){
            cout << 0 << "\n";
        } else {
            cout << 1 << "\n";
        }
    }
    return 0;
}
