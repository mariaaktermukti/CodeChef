#include <bits/stdc++.h>
using namespace std;
int main() 
{
  int t;
  cin >> t;
  while(t--) 
  {
    int n,k;
    cin >> n >> k;
    int a[n + 1];
    for(int i = 1;i <= n;i++) 
    {
        cin >> a[i];
    }
    int ans = 0;
    int count = 0;
    for(int i = 1;i <= n;i++) 
    {
      if(a[i] == 1) 
      {
        ans= ans + (count + 1)/(k + 1);
        count = 0;
        continue;
      }
      else 
      {
        count++;
      }
    }
    ans= ans + (count + 1)/(k + 1);
    cout << ans << endl;
  }
}