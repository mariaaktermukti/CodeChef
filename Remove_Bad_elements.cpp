#include <iostream>
#include <algorithm>
using namespace std;

int main() 
{
	int t,n,arr[100001];
	cin >> t;
	
	while(t--)
    {
	    cin >> n;
	    for(int i = 0; i < n; i++)
        {
	        cin >> arr[i];
	    }
	    sort(arr, arr+n);
	    int cnt = 1 , maxcnt = 1;
	    
	    for(int i = 0; i < n-1; i++)
        {
	        if(arr[i] == arr[i+1])
            {
	            cnt++;
	        }
	        else cnt = 1;
	        maxcnt = max(maxcnt, cnt);
	    }
	    
	    cout << n-maxcnt << endl;
	}
	
	return 0;
}