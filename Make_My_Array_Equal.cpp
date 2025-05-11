
#include <bits/stdc++.h>
#define lil long long int
const int MOD = 1e9 + 7;
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
	int test;cin>>test;
	while(test--)
	{
	    lil n;cin>>n;
	    lil a[n];
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	    
	    sort(a,a+n);
	    if(n==1){
	        cout<<"YES\n";
	    }
	    else if(n==2)
	    {
	        if(a[0]==a[1] || a[0]==0||a[1]==0) cout<<"YES\n";
	        else cout<<"NO\n";
	    }
	    else
	    {
	        int c=0;
	        for(int i=0;i<n-1;i++)
	        {
	            if(a[i]==0)
	            {
	                continue;
	            }
	            else if(a[i]!=a[i+1])
	            {
	                c=1;break;
	            }
	        }
	        if(c==1) cout<<"NO\n";
	        else cout<<"YES\n";
	    }
	}

}