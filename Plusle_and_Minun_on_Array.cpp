#include <bits/stdc++.h>
using namespace std;

int main() 
{
    int t;
    cin>>t;
    while(t--)
    {
     int long long n,mx=INT_MIN,mn=INT_MAX,sum=0,sum1=0;
     cin>>n;
     int long long a[n];
     for(int i=0;i<n;i++)
     {
         cin>>a[i];
         if(i&1)
         {
             sum1+=abs(a[i]);
             mx=max(mx,abs(a[i]));
         } 
         else 
         {
             sum+=abs(a[i]);
             mn=min(mn,abs(a[i]));
         }
     }
     if(mx<=mn)
     {
        cout<<(sum-sum1)<<endl;
     }
     else 
     {
        cout<<(sum-sum1)+(2*(mx-mn))<<endl;
     }
    }
	return 0;
}