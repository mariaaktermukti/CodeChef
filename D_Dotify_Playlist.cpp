#include <bits/stdc++.h>
using namespace std;

int main() 
{
    int T;
    cin >> T;
    while (T--) {
        int N, K, L;
        cin >> N >> K >> L;
        vector<int> lengths;
        for (int i = 0; i < N; ++i) 
        {
            int M, lang;
            cin >> M >> lang;
            if (lang == L) 
            {
                lengths.push_back(M);
            }
        }

        if ((int)lengths.size() < K) 
        {
            cout << -1 << endl;
        } 
        else 
        {
            sort(lengths.rbegin(), lengths.rend());
            int total = 0;
            for (int i = 0; i < K; ++i) 
            {
                total += lengths[i];
            }
            cout << total << endl;
        }
    }
    return 0;
}
