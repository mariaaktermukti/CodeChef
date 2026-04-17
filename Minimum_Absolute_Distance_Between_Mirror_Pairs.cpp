#include <bits/stdc++.h>
using namespace std;

int reverseDigits(int num)
{
    int reversed = 0;
    while (num > 0)
    {
        reversed = reversed * 10 + (num % 10);
        num /= 10;
    }
    return reversed;
}

int main()
{
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    unordered_map<int, int> indexMap;
    int minDistance = INT_MAX;

    for (int j = 0; j < n; j++)
    {
        if (indexMap.count(nums[j]))
        {
            minDistance = min(minDistance, j - indexMap[nums[j]]);
        }

        int reversed = reverseDigits(nums[j]);
        indexMap[reversed] = j;
    }

    if (minDistance == INT_MAX)
        cout << -1 << endl;
    else
        cout << minDistance << endl;

    return 0;
}