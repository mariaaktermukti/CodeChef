#include <bits/stdc++.h>
using namespace std;

int main() 
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        
        string a,b;
        cin>>a>>b;
        
        int c =0 ;
        for(int i=0; i<n; i++)
        {
            if(a[i] == '1')
            {
                c++;
            }
            
            if(b[i] == '1')
            {
                c--;
            }
        }
        
        if(c != 0)
        {
            cout<<"NO"<<endl;
        }
        else
        {
            c = 0;
            int d =0;
            
            for(int i=0; i<n; i++)
            {
                if(a[i] != b[i])
                {
                    c++;
                }
                
                if(a[i] == '1')
                {
                    d++;
                }
            }
            
            c /= 2;
            if(k < c)
            {
                cout<<"NO"<<endl;
            }
            else
            {
                if(d>1 || (n-d)>1)
                {
                    cout<<"YES"<<endl;
                }
                else if((k-c)%2==0)
                {
                    cout<<"YES"<<endl;
                }
                else
                {
                    cout<<"NO"<<endl;
                }
            }
        }
    }
}