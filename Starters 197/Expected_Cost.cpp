#include <bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin >> T;
    while (T--) 
    {
        int N;
        cin >> N;
        vector<double> A(N+1), B(N+1);
        for (int i = 1; i <= N; i++) cin >> A[i];
        for (int i = 1; i <= N; i++) cin >> B[i];

        double lo = 0.0, hi = 0.0;
        for (int i = 1; i <= N; i++) hi += A[i];
        hi += 1;  

        vector<double> E(N+2);
        const int M = N+1;
        for (int it = 0; it < 80; it++) 
        {
            double mid = 0.5*(lo + hi);
            E[N+1] = 0.0;
            double sumE = 0.0; 
            sumE += E[N+1];
            for (int i = N; i >= 1; i--) 
            {
                double go = A[i] + E[i+1];
                double rnd = B[i] + mid;
                E[i] = min(go, rnd);
                sumE += E[i];
            }
            double Sprime = sumE / M;
            if (Sprime > mid) 
            {
                lo = mid;
            } 
            else 
            {
                hi = mid;
            }
        }

        double S = 0.5*(lo + hi);
        E[N+1] = 0.0;
        for (int i = N; i >= 1; i--) 
        {
            E[i] = min(A[i] + E[i+1], B[i] + S);
        }

        cout << fixed << setprecision(6) << E[1] << "\n";
    }

    return 0;
}
