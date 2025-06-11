#include <bits/stdc++.h>
using namespace std;
struct TwoSAT {
    int N;
    vector<vector<int>> adj, adj_rev;
    vector<int> comp, order, vis, assignment;
    TwoSAT(int n): N(n) {
        adj.assign(2*N, {});
        adj_rev.assign(2*N, {});
    }
    void add_imp(int u, int v) {
        adj[u].push_back(v);
        adj_rev[v].push_back(u);
    }
    void add_or(int a, int b) {
        add_imp(a^1, b);
        add_imp(b^1, a);
    }
    void add_true(int a) {
        add_imp(a^1, a);
    }
    void dfs1(int u) {
        vis[u] = 1;
        for(int v: adj[u])
            if(!vis[v]) dfs1(v);
        order.push_back(u);
    }
    void dfs2(int u, int c) {
        comp[u] = c;
        for(int v: adj_rev[u])
            if(comp[v] < 0) dfs2(v, c);
    }
    bool solve() {
        vis.assign(2*N,0);
        order.clear();
        for(int i=0;i<2*N;i++)
            if(!vis[i]) dfs1(i);
        comp.assign(2*N, -1);
        int cid = 0;
        for(int i=2*N-1;i>=0;i--) {
            int u = order[i];
            if(comp[u]<0)
                dfs2(u, cid++);
        }
        assignment.assign(N, 0);
        for(int i=0;i<N;i++) {
            if(comp[2*i] == comp[2*i+1])
                return false; 
            assignment[i] = comp[2*i] > comp[2*i+1];
        }
        return true;
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; 
    cin >> T;
    while(T--){
        int N; 
        string S;
        cin >> N >> S;

        TwoSAT sat(N);
        bool ok = true;
        for(int j = 0; j < N; j++){
            if(S[j] == '0'){
                vector<int> lits;
                if(j-1 >= 0 && S[j-1]=='1'){
                    lits.push_back(2*(j-1));
                }
                if(j+1 < N && S[j+1]=='1'){
                    lits.push_back(2*(j+1) + 1);
                }
                if(lits.empty()){
                    ok = false;
                    break;
                }
                else if(lits.size()==1){
                    sat.add_true(lits[0]);
                }
                else {
                    sat.add_or(lits[0], lits[1]);
                }
            }
        }

        if(!ok){
            cout << "No\n";
            continue;
        }
        bool sat_res = sat.solve();
        cout << (sat_res ? "Yes\n" : "No\n");
    }
    return 0;
}
