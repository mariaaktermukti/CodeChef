#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct SegTree {
    struct Node {
        ll sum, mul;
    };
    int N;
    vector<Node> st;
    SegTree(int n): N(n), st(4*n) {
        build(1, 0, N-1);
    }
    void build(int p, int l, int r) {
        st[p].sum = 0;
        st[p].mul = 1;
        if (l==r) return;
        int m=(l+r)/2;
        build(p<<1, l, m);
        build(p<<1|1,m+1,r);
    }
    inline void applyMul(int p, ll factor) {
        st[p].sum *= factor;
        st[p].mul *= factor;
    }
    void push(int p) {
        if (st[p].mul!=1) {
            applyMul(p<<1,   st[p].mul);
            applyMul(p<<1|1, st[p].mul);
            st[p].mul = 1;
        }
    }
    void pull(int p) {
        st[p].sum = st[p<<1].sum + st[p<<1|1].sum;
    }
    void rangeMul(int p, int l, int r, int L, int R) {
        if (R<l || r<L) return;
        if (L<=l && r<=R) {
            applyMul(p, 2);
            return;
        }
        push(p);
        int m=(l+r)/2;
        rangeMul(p<<1,   l,   m, L, R);
        rangeMul(p<<1|1, m+1, r, L, R);
        pull(p);
    }
    void pointAdd(int p, int l, int r, int idx) {
        if (l==r) {
            st[p].sum += 1;
            return;
        }
        push(p);
        int m=(l+r)/2;
        if (idx<=m) pointAdd(p<<1, l, m, idx);
        else        pointAdd(p<<1|1, m+1, r, idx);
        pull(p);
    }
    ll rangeSum(int p, int l, int r, int L, int R) {
        if (R<l || r<L) return 0;
        if (L<=l && r<=R) return st[p].sum;
        push(p);
        int m=(l+r)/2;
        return rangeSum(p<<1, l, m, L, R)
             + rangeSum(p<<1|1, m+1, r, L, R);
    }

    void multiplyAll()        { rangeMul(1,0,N-1, 0,N-1); }
    void incrementAt(int i)   { pointAdd(1,0,N-1, i); }
    ll  prefixSum(int i)      { return i<0?0LL: rangeSum(1,0,N-1, 0,i); }
    ll  pointQuery(int i)     { return rangeSum(1,0,N-1, i,i); }
};


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; 
    cin >> T;
    while(T--){
        int M;
        cin >> M;
        vector<int> ops(M);
        for(int i=0;i<M;i++) 
            cin >> ops[i];

        SegTree st(M+5);

        ll inv = 0,         
        inv_cross = 0;  
        ll len = 1;          
        int mex = 1;        
        st.incrementAt(0);   

        vector<ll> answer;
        answer.reserve(M);

        for(int t: ops){
            if (t==1) {
                ll small = st.prefixSum(mex-1);
                inv += small;
                inv_cross  += (len - st.pointQuery(mex));
                st.incrementAt(mex);
                len++;
                while (st.pointQuery(mex)>0) 
                    mex++;
            }
            else {
                inv = inv*2 + inv_cross;
                inv_cross *= 4;
                st.multiplyAll();
                len *= 2;
            }

            answer.push_back(inv);
        }

        for(int i=0;i<M;i++){
            cout << answer[i] << (i+1==M?'\n':' ');
        }
    }

    return 0;
}
