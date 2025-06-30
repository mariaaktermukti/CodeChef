#include <iostream>
#include <string>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--)
    {
	    int n,x,s;
	    cin>>n>>x>>s;
	    for(int i=1;i<=s;i++)
        {
	        int a,b;
	        cin>>a>>b;
	        if(b==x) x=a;
	        else if(a==x) x=b;
	        
	    }
	    cout<<x<<endl;
	}
	return 0;
}