#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 998244353;

int add(int a, int b){ a+=b; if(a>=MOD) a-=MOD; return a; }
int mul(ll a, ll b){ return int((a*b)%MOD); }

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while(T--)
    {
        int N;
        cin >> N;
        vector<int> A(N);
        for(int i = 0; i < N; i++)
        {
            cin >> A[i];
        }
        int V = 2 * N;
        vector<vector<int>> adj(V);
        for(int i = 0; i < N; i++)
        {
            int x = A[i] + 1;       
            int y = N - A[i];       
            --x;  
            --y;
            adj[i].push_back(N + x);
            adj[N + x].push_back(i);
            if(x != y)
            {
                adj[i].push_back(N + y);
                adj[N + y].push_back(i);
            }
        }

        vector<char> vis(V, 0);
        bool ok = true;
        int ans = 1;
        for(int u = 0; u < V; u++)
        {
            if(vis[u] || adj[u].empty()) continue;
            stack<int> st;
            st.push(u);
            vis[u] = 1;
            int cnt_nodes = 0;
            int cnt_persons = 0;
            int cnt_positions = 0;
            ll edge_degree_sum = 0;

            while(!st.empty())
            {
                int v = st.top(); st.pop();
                cnt_nodes++;
                if(v < N) cnt_persons++;
                else       cnt_positions++;
                edge_degree_sum += (int)adj[v].size();
                for(int w: adj[v])
                {
                    if(!vis[w]){
                        vis[w] = 1;
                        st.push(w);
                    }
                }
            }

            int E = int(edge_degree_sum / 2);
            if(cnt_persons != cnt_positions){
                ok = false;
                break;
            }
            if(E == cnt_nodes - 1)
            {
            }
            else if(E == cnt_nodes)
            {
                ans = mul(ans, 2);
            }
            else 
            {
                ok = false;
                break;
            }
        }

        cout << (ok ? ans : 0) << "\n";
    }

    return 0;
}
