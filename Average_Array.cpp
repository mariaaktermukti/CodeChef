#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main() 
{
	ll t,n,i,j,k;
	cin >> t;
	while(t--)
	{
	    cin >> n >> k;
	    if(n&1)
        {
             cout << k << " ";
        }
	       
	    for(i=1;i<=(n/2);i++)
	    {
	        cout << k+i << " " << k-i << " ";
	    }
	    cout << "\n";
	}
	return 0;
}