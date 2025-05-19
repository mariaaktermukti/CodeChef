#include <iostream>
#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    ll x;
	    cin>>x;
	    ll x1=x;
	    vector<int>v1;
	    while(x1!=0)
	    {
	        if(x1%2==0)
	        {
	            v1.push_back(0);
	        }
	        else
	        {
	            v1.push_back(1);
	        }
	        x1=x1>>1;
	        
	    }
	    ll i,c1=0,j=0;
	    for(i=v1.size()-1;i>=0;i--)
	    {
	        if(v1[i]==1)
	        {
	          
	            j++;
	        }
	        else 
	        {
	            if(j>=2)
	            c1++;
	        }
	    }
	    cout<<(1<<c1)<<endl;
	}
	return 0;
}