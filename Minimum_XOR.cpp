#include <bits/stdc++.h>
using namespace std;

int findMinimumXOR(vector<int>& nums) 
{
	int n = nums.size();
	sort(nums.begin(), nums.end());
	int result = 0;
	for (int i = 0; i < n; ++i)
    {
		result ^= nums[i];
	}

	int min_xor = result;

	for (int i = 0; i < n; ++i) 
    {
		int xor_after_removal = result ^ nums[i];
		min_xor = min(min_xor, xor_after_removal);
	}

	return min_xor;
}

int main() 
{
	int t, a, n;
	scanf("%d", &t);
	while (t--)
	{
		vector<int> nums;
		scanf("%d", &n);
		for (int i = 0; i<n; i++)
		{
			scanf("%d", &a);
			nums.push_back(a);
		}
		int result = findMinimumXOR(nums);
		printf("%d\n", result);
	}
	return 0;
}