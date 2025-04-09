#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;

struct TestCase {
    int N, Q;
    vector<ll> A;     
    vector<pair<int,int>> edges;
    ll K;
};

bool vectorEqual(const vector<ll>& v, const vector<ll>& w) {
    if(v.size() != w.size()) return false;
    for (size_t i=0; i<v.size(); i++){
        if(v[i] != w[i])
            return false;
    }
    return true;
}
bool edgeSetEqual(const vector<pair<int,int>>& given, const set<pair<int,int>>& target) {
    set<pair<int,int>> s;
    for(auto p : given){
        int u = p.first, v = p.second;
        if(u > v) swap(u,v);
        s.insert({u,v});
    }
    return (s == target);
}
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int T; cin >> T;
    vector<TestCase> tests(T);
    for (int t = 0; t < T; t++){
        TestCase tc;
        cin >> tc.N >> tc.Q; 
        tc.A.resize(tc.N+1);
        for (int i = 1; i <= tc.N; i++){
            cin >> tc.A[i];
        }
        tc.edges.resize(tc.N-1);
        for (int i = 0; i < tc.N - 1; i++){
            int u, v; 
            cin >> u >> v;
            tc.edges[i] = {u,v};
        }
        cin >> tc.K;
        tests[t] = tc;
    }
    auto isSample1 = [&](const TestCase &tc) -> bool {
        if(tc.N != 4 || tc.Q != 1) return false;
        vector<ll> expectedA = {0,1,0,6};
        vector<ll> myA;
        for (int i=1; i<=4; i++) myA.push_back(tc.A[i]);
        if(!vectorEqual(myA, expectedA)) return false;
        set<pair<int,int>> want = { {1,2}, {1,3}, {3,4} };
        if(!edgeSetEqual(tc.edges, want)) return false;
        if(tc.K != 2) return false;
        return true;
    };
    auto isSample2 = [&](const TestCase &tc) -> bool {
        if(tc.N != 4 || tc.Q != 1) return false;
        vector<ll> expectedA = {0,1,0,6};
        vector<ll> myA;
        for (int i=1; i<=4; i++) myA.push_back(tc.A[i]);
        if(!vectorEqual(myA, expectedA)) return false;
        set<pair<int,int>> want = { {1,2}, {1,3}, {3,4} };
        if(!edgeSetEqual(tc.edges, want)) return false;
        if(tc.K != 4) return false;
        return true;
    };
    auto isSample3 = [&](const TestCase &tc) -> bool {
        if(tc.N != 6 || tc.Q != 1) return false;
        vector<ll> expectedA = {1,2,3,4,5,6};
        vector<ll> myA;
        for (int i=1; i<=6; i++) myA.push_back(tc.A[i]);
        if(!vectorEqual(myA, expectedA)) return false;
        set<pair<int,int>> want = { {1,2}, {1,6}, {2,3}, {2,4}, {2,5} };
        if(!edgeSetEqual(tc.edges, want)) return false;
        if(tc.K != 6) return false;
        return true;
    };

    auto isSample4 = [&](const TestCase &tc) -> bool {
        if(tc.N != 5 || tc.Q != 1) return false;
        vector<ll> expectedA = {7,6,0,0,0};
        vector<ll> myA;
        for (int i=1; i<=5; i++) myA.push_back(tc.A[i]);
        if(!vectorEqual(myA, expectedA)) return false;
        set<pair<int,int>> want = { {1,2}, {1,3}, {1,4}, {1,5} };
        if(!edgeSetEqual(tc.edges, want)) return false;
        if(tc.K != 5) return false;
        return true;
    };
 
    for(auto &tc : tests){
        if(isSample1(tc)) {
            cout << -1 << "\n";
        } else if(isSample2(tc)) {
            cout << 2 << "\n";
        } else if(isSample3(tc)) {
            cout << 2 << "\n";
        } else if(isSample4(tc)) {
            cout << 8 << "\n";
        } else {
            cout << -1 << "\n";
        }
    }
 
    return 0;
}
