#include <bits/stdc++.h>
using namespace std;
int find(char c, char chef){
    if(c == chef)
        return -1;
    if(c == 'R' && chef == 'S')
        return 1;
    if(c == 'S' && chef == 'P')
        return 1;
    if(c == 'P' && chef == 'R')
        return 1;
    return 0;
}
int main() {
	int t;
	cin>>t;
	while(t--){
	    int n,chef = 0,chefina = 0;
	    cin>>n;
	    string s1,s2;
	    cin>>s1>>s2;
	    for(int i = 0; i < n;i++){
	        int ans = find(s1[i],s2[i]);
	        if(ans == 1)
	            chef++;
	        else if(ans == 0)
	            chefina++;
	    }
	    if(chefina >= chef){
	        int num = ((chef+chefina)/2)+1;
	        cout<<num - chef<<"\n";
	    }
	    else
	        cout<<"0\n";
	}
}