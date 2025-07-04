#include <bits/stdc++.h>
using namespace std;

int main() 
{
	int t,n,k;
    cin>>t;
	while(t--)
    {
	   cin>>n;
	   int arr[n+1];
	   int j;
	   for(int i=0;i<n;i++)
       {
        cin>>arr[i];
       }
	   cin>>k;
	   int m = arr[k-1];
	   sort(arr,arr+n);
	   for(int i=0;i<n;i++) 
       {
          if( m == arr[i]) 
          {
            j = i;
          }
       }  
	   cout<<j+1<<endl;
	}
	return 0;
}