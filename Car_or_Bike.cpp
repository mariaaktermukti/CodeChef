#include <iostream>
#include<math.h>
using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int a,b;
	    cin>>a>>b;
	    if(a>b)
        {
            cout<<"CAR"<<endl;
        }
	    else if(b>a)
        {
            cout<<"BIKE"<<endl;
        }
	    else
        {
            cout<<"SAME"<<endl;
        }
	    
	}
	return 0;
}
