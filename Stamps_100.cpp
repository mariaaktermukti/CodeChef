#include<bits/stdc++.h>
#define ll long long 
#define endl "\n"
const int mod = 1e9+7;
using namespace std;
 
int main()
{
    int t;  cin>>t;
    while(t--)
    {
        int n; cin>>n;
        string s; cin>>s;
        int pos = 0;
        while(s[pos]!='1')
        {
            pos++;
        }
        for(int i = n-3; i>=pos; i--)
        { 
            s[i] = '1';
            s[i+1] = '0';
            s[i+2] = '0'; 
        }
        cout<<s<<endl;
    }
    return 0;
}