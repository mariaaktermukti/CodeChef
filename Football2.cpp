#include<bits/stdc++.h>
using namespace std;

int main() {
	long long int t;
	cin>>t;
	while(t--)
	{
	    long long int n;
	    cin>>n;
	    long long int a[n],b[n],c[n];
	    for(int i=0;i<n;i++) cin>>a[i];
	    for(int i=0;i<n;i++) cin>>b[i];
	    for(int i=0;i<n;i++) c[i]=(a[i]*20)-(b[i]*10);
	    for(int i=0;i<n;i++) if(c[i]<0) c[i]=0;
	    cout<<*max_element(c,c+n)<<endl;
	    
	    
	    
	}
	return 0;
}