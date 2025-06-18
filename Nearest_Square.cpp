#include<bits/stdc++.h>
using namespace std;
int main()
{
    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;
        int i=1;
        int Ans=1;
        while (i*i<=N) 
        {
            Ans=i*i;
            i++;
        }

        cout <<Ans<< endl;
    }
    return 0;
}