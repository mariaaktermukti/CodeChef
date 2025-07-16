#include <bits/stdc++.h>
using namespace std;

int main() {
	int t; cin>>t;
	while(t--)
    {
	    int n; cin>>n;
	    vector<int> a(n),b(n);
	    int sum = 0;
	    for(int i=0;i<n;i++) 
        {
            cin>>a[i];
        }
	    for(int i=0;i<n;i++)
        {
	        cin>>b[i];
	        if(b[i]<a[i]) 
            {
                sum =sum + a[i]-b[i];
            }
	    }
	    cout<<sum<<endl;
	}

}