#include <bits/stdc++.h>
using namespace std;

int main() 
{
	int t;
	cin>>t;
	while(t--)
    {
	    int n,m;
	    unordered_map<int,int> mp;
	    cin>>n>>m;
	    for(int i=0;i<n;i++)
        {
	        int a;
	        cin>>a;
	        mp[a]++;
	    }
        
	    int cnt=0;
	  for(auto i:mp)
      {
	      cnt++;
	  }

	  cout<<m-cnt<<endl;
	}

}