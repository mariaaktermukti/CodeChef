#include <bits/stdc++.h>
using namespace std;

bool check(vector<long long> &v,vector<long long> &p,long long n,long long mid){
    long long pos = 0,neg = 0;
    for(int i = 0;i < n;i++){
        if((v[i] + p[i]) >= mid) pos += (2*1LL*((v[i]+p[i])-mid));
        else{
            neg += (mid - (v[i]+p[i]));
            if((mid-v[i]-p[i])&1) neg--;
        }
    }
    if(neg >= pos) return true;
    return false;
}

int main() {
	int t;
	cin>>t;
	while(t--){
    	long long n;
    	cin>>n;
	    vector<long long> v(n),p(n);
	    for(auto &i:v) cin>>i;
	    for(auto &i:p) cin>>i;
	    long long mx = INT_MIN,tmx = INT_MIN;
	    for(int i = 0;i<n;i++) mx = max(mx,v[i]);
	    for(int i = 0;i<n;i++) tmx = max(tmx,(v[i]+p[i]));
	    long long low = mx,high = tmx;
	    long long ans = LLONG_MAX;
	    while(low <= high){
	        long long mid = (low+high)/2;
	        if(check(v,p,n,mid)){
	            ans = min(ans,mid);
	            high = mid-1;
	        }
	        else low = mid+1;
	    }
	    cout<<ans<<endl;
	}
}