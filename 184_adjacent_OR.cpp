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
        vector<int> A(N+2), B(N+2);
        for(int i=1;i<=N;i++) cin >> A[i];
        for(int i=1;i<=N;i++) cin >> B[i];

        if(B[1]!=A[1] || B[N]!=A[N]){
            cout<<"No\n";
            continue;
        }

        bool ok = true;
        for(int i=2;i<N;i++){
            if(B[i]==0 && B[i-1]==1 && B[i+1]==1){
                ok = false;
                break;
            }
        }
        if(!ok){
            cout<<"No\n";
            continue;
        }
        int i = 1;
        while(i <= N && ok){
            if(B[i]==1){
                int j = i;
                while(j+1<=N && B[j+1]==1) j++;
                bool seeded = false;
                for(int k=i; k<=j; k++){
                    if(A[k]==1){ seeded = true; break; }
                }
                if(!seeded && i>1 && A[i-1]==1) seeded = true;
                if(!seeded && j<N && A[j+1]==1) seeded = true;

                if(!seeded) ok = false;
                i = j+1;
            } else {
                i++;
            }
        }
        if(!ok){
            cout<<"No\n";
            continue;
        }
        for(int i=2;i<N;i++){
            if(A[i]==1 && B[i]==0){
                if(!(A[i-1]==0 && A[i+1]==0)){
                    ok = false;
                    break;
                }
            }
        }

        cout << (ok ? "Yes\n" : "No\n");
    }
    return 0;
}
