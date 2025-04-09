#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while(T--){
        int N;
        cin >> N;
        vector<vector<int>> adj(N+1);
        for(int i = 2; i <= N; i++){
            int p;
            cin >> p;
            adj[p].push_back(i);
            adj[i].push_back(p);
        }
        // 1) Check degree > 2
        bool ok = true;
        for(int i = 1; i <= N; i++){
            if(adj[i].size() > 2){
                ok = false;
                break;
            }
        }
        // 2) If N odd, impossible
        if(N % 2 == 1) ok = false;

        if(!ok){
            cout << -1 << "\n";
            continue;
        }
        // It's an even-length path. Find one endpoint.
        int start = 1;
        for(int i = 1; i <= N; i++){
            if(adj[i].size() == 1){
                start = i;
                break;
            }
        }
        // Walk the path
        vector<int> order;
        order.reserve(N);
        vector<bool> vis(N+1,false);
        int cur = start, prev = 0;
        while(true){
            order.push_back(cur);
            vis[cur] = true;
            int nxt = 0;
            for(int v: adj[cur]){
                if(v != prev){
                    nxt = v;
                    break;
                }
            }
            if(nxt == 0) break;
            prev = cur;
            cur = nxt;
        }
        // Assign colours by pairing
        vector<int> C(N+1);
        int half = N/2;
        for(int i = 0; i < half; i++){
            int u = order[i];
            int v = order[N-1-i];
            int colour = i+1;
            C[u] = colour;
            C[v] = colour;
        }
        // Output
        for(int i = 1; i <= N; i++){
            cout << C[i] << (i==N?'\n':' ');
        }
    }
    return 0;
}
