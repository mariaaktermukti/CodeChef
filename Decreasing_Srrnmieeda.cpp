#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main() 
{
	ll t,l,r;
	cin >> t;
	while(t--)
	{
	    cin >> l>>r;
	    if(l<=(r/2) || l==1ll)
        {
            cout << "-1\n";
        }    
	    else
        {
            cout << r << "\n";
        }
	        
	}
	return 0;
}