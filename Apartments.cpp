#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() 
{
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> applicants(n);
    vector<int> apartments(m);

    for (int i = 0; i < n; ++i) 
    {
        cin >> applicants[i];
    }
    for (int i = 0; i < m; ++i) 
    {
        cin >> apartments[i];
    }

    sort(applicants.begin(), applicants.end());
    sort(apartments.begin(), apartments.end());

    int i = 0, j = 0, matches = 0;
    while (i < n && j < m) 
    {
        if (abs(applicants[i] - apartments[j]) <= k) 
        {
            ++matches;
            ++i;
            ++j;
        } 
        else if (apartments[j] < applicants[i] - k) 
        {
            ++j;
        } 
        else 
        {
            ++i;
        }
    }

    cout << matches << endl;
    return 0;
}
