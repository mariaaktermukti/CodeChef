#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() 
{
	int t; cin>>t;
	while(t--)
    {
	    int n; cin>>n;
	   int ans=INT_MAX;
	    for(int i=0;i<n;i++) 
        {
	       int a;
	       cin>>a;
	       ans = ans & a;
	    }
	    cout<<ans<<endl;
	}
    return 0;
}