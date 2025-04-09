#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    cin >> T;
    
    while(T--){
        int N, M;
        cin >> N >> M;
        vector<vector<long long>> A(N, vector<long long>(M));
        for (int i = 0; i < N; i++){
            for (int j = 0; j < M; j++){
                cin >> A[i][j];
            }
        }
        
        long long total = N * M;
        long long bestChanges = total; 
        int patterns[4][2] = { {1,1}, {1,-1}, {-1,1}, {-1,-1} };
        
        for (int k = 0; k < 4; k++){
            int p = patterns[k][0];
            int q = patterns[k][1];
            unordered_map<long long, int> freq;
            int maxFreq = 0;

            for (int i = 0; i < N; i++){
                for (int j = 0; j < M; j++){
                    long long candidate = A[i][j] - ( (long long)p * i + (long long)q * j );
                    int count = ++freq[candidate];
                    maxFreq = max(maxFreq, count);
                }
            }
            
            long long changes = total - maxFreq;
            bestChanges = min(bestChanges, changes);
        }
        
        cout << bestChanges << "\n";
    }
    return 0;
}
