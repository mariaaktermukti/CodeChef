#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--)
    {
        float n,x;
        cin>>n>>x;
        if(n<=x)
        {
            cout<<0<<endl;
        }
        else
        {
            cout<<ceil((n-x)/4)<<endl;
        }
    }
	return 0;
}