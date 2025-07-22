#include <bits/stdc++.h>
using namespace std;

int main() 
{
	int leo;
	cin>>leo;
	while(leo-- >0)
    {
	    int n;
	    cin>>n;
	    int a[n];
	    for(int i=0;i<n;i++)
        {
	        cin>>a[i];
	    }

	    int s=0;
	    bool flag=false;
	    double avg;
	    
	    for(int i=0;i<n;i++)
        {
	        s+=a[i];
	        double avg = (double)s / (i + 1);
	        if(avg<40)
            {
	            flag=true;
	            cout<<"NO"<<endl;
	            break;
	        }
	        
	    }
	    if(!flag)
        {
	        cout<<"YES"<<endl;
	    }
	    
	}

}