#include<bits/stdc++.h>
using namespace std;
void solve()
{

    int n,k;
    cin>>n>>k;
    vector<string> v;
    for(int i=0;i<n;i++)
    {
        string e;
        cin>>e;
        v.push_back(e);
    }
    set<string> st;
    for(string s:v)st.insert(s);
    string temp="";
    for(int i=0;i<k;i++)
    {
        temp.push_back('0');
    }
    for(int i=k-1;i>=0;i--)
    {
        temp[i]='1';
        if(st.find(temp)==st.end())
        {
            cout<<"NO"<<endl;
            return ;
        }
        temp[i]='0';
        
    }
    cout<<"YES"<<endl;

    
}


int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }
}