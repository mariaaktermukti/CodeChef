#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;

    if (N <= 3) 
    {
        vector<int> p(N);
        iota(p.begin(), p.end(), 1);
        int M = 0;
        vector<vector<int>> all;
        do 
        {
            all.push_back(p);
            M++;
        } while (next_permutation(p.begin(), p.end()));
        cout << M << "\n";
        for (auto &perm : all) 
        {
            for (int i = 0; i < N; i++) 
            {
                cout << perm[i] << (i+1==N?'\n':' ');
            }
        }
    }
    else 
    {
        cout << 2 << "\n";
        for (int i = 1; i <= N; i++) 
        {
            cout << i << (i==N?'\n':' ');
        }
        for (int i = N; i >= 1; i--) 
        {
            cout << i << (i==1?'\n':' ');
        }
    }

    return 0;
}
