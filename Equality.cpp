#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int N; cin>>N;
    long long int A[N];
    long long int Array_sum = 0, X_sum ;
    
    for(int i=0;i<N;i++) 
    {
        cin>>A[i];
        Array_sum += A[i];
    }
    
    X_sum = Array_sum / (N-1);
    for(int i=0;i<N;i++) 
    {
        cout<<X_sum - A[i]<<" ";
    }
    cout<<endl;
    
    
}

int32_t main() 
{
	int tc = 0; 
    cin>>tc;
	while(tc--) 
    {
        solve();
    }
	return 0;
}