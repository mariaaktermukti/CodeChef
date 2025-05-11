#include <bits/stdc++.h>
using namespace std;

int main() {
	int t; cin>>t;
	while(t--){
	    int n ;cin>>n;
	    int q; cin>>q;
	    
	    
	    int a[n];
	    for(int i = 0 ; i<n; i ++)cin>>a[i];
	    
	    int que[q];
	    for(int i = 0 ; i<q ; i++)cin>>que[i];
	    
	    sort(a, a+n);
	    int sum =0;
	    for(int i = 0 ; i<n ; i++){
	        sum+=a[i];
	    }
	    
	    
	    
	    for(auto num : que){
	        if(num>=2*sum){
	            cout<<-1<<endl;
	            continue;
	        }
            int i1 =-1 , i2=-1 ;
    	        for(int i= 0 ; i<n ; i++){
    	            for(int j= i+1 ; j<n ; j++){
    	                if(a[i] + a[j] +num ==2*sum ){
    	                    i1 = i;i2 = j;
    	                    break;
    	                }
    	            }
    	        }
            if(i1 != -1){
                cout<<a[i1]<<" ";
                for(int i= 0 ; i<n; i ++){
                    if(i == i1 || i ==i2)continue;
                    cout<<a[i]<<" ";
                    
                }
                cout<<a[i2]<<endl;
            }else{
                cout<<-1<<endl;
            }
	    }
	    
	}
	

}