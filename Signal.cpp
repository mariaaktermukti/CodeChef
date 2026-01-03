#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    string s;
	    cin>>n>>s;
	    bool f=false;
	    int cnt=0;
	    for(char c:s)
	    {
	        if(c=='0')
	        f=true;
	        else if(f&&c=='1')
	        cnt++;
	    }
	    cout<<cnt<<endl;
	}
	return 0;
}