#include <iostream>
#define ll long long
using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--)
	{
	    ll int n;
	    cin >> n;
	    ll int a[n];
	    for(ll int i=0;i<n;i++)
	    {
	        cin >> a[i];
	    }
	    
	    ll int sum = 0;
	    for(ll int i=0;i<n-1;i++)
	    {
	        sum+=abs(a[i+1]-a[i]);
	    }
	    
	    cout << sum-(n-1) << endl;
	}
	return 0;
}