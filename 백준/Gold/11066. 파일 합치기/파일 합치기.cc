#include <iostream>
#include <algorithm>
#include <limits.h>

using namespace std;

int dp[501][501];
int cost[501];
int sum[501];

int main()
{
	int testcase;
	cin >> testcase;
	for (int t = 0; t < testcase; t++)
	{
		int k;
		cin >> k;

		//make cost
		for (int i = 1; i <= k; i++)
		{
			cin >> cost[i];
		}

		//make sum
		for (int i = 1; i <= k; i++)
		{
			if (i == 1)
				sum[i] = cost[i];
			else
				sum[i] = sum[i - 1] + cost[i];
		}

		//solve
		for (int gap = 1; gap < k; gap++)
		{
			for (int start = 1; start + gap <= k; start++)
			{
				int end = start + gap;

				dp[start][end] = INT_MAX;

				for (int mid = start; mid < end; mid++)
				{
					dp[start][end] = min(dp[start][end], dp[start][mid] + dp[mid + 1][end] + sum[end] - sum[start-1]);
				}
			}
		}
		cout << dp[1][k] << endl;
	}
	return 0;
}