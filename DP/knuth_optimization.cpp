/*
We never revisit a node because when we decided to move away from it to a node with subtree size greater than n/2, we sort of declared that it now belongs to the component with nodes less than n/2, and we shall never find our centroid there. 

In any case we are moving towards the centroid. Also, there are finitely many vertices in the tree. The process must stop, and it will, at the desired vertex.


Optimal solution (using Knuth’s optimization):

The conditions for applying Knuth’s optimization hold for this question:

cost(i, j) is merely the sum of all elements in the subarray bounded by the indices i and j. Further, the transition function of dynamic programming matches the general case for applying this technique.

Follow the steps mentioned here to implement the idea of Knuth optimization:

Define the array opt[N][N] and the dp[][] array. 
Now, process subarrays in increasing order of length, with the initial state dp[i][i] = 0, and opt[i][i] = i (because the value should be i to minimize the value dp[i][i]).
Thus, when we reach the subarray arr[i, . . ., j], the value of opt[i][j-1] and opt[i+1][j] are already known. So, only check for the condition opt[i][j-1] ≤ k ≤ opt[i+1][j], to find opt[i][j] and dp[i][j]. 
Here also the cost function is calculated in the same way as in the previous approach using the prefix sum array.
Note: In the code given below different way of looping through all sub-arrays is used (instead of looping in increasing order of length), However, ensuring that opt[i+1][j] and opt[i][j-1] are calculated before dp[i][j].

Below is the implementation of the above approach. 
*/

// C++ code to implement the approach

#include <bits/stdc++.h>
using namespace std;

// Function to find the minimum possible cost
int minCost(int arr[], int N)
{
	// Creating the prefix sum array
	int pref[N + 1], dp[N][N], opt[N][N];
	pref[0] = 0;
	memset(dp, 0, sizeof(dp));
	memset(dp, 0, sizeof(dp));

	// Loop to calculate the prefix sum
	for (int i = 0; i < N; i++) {
		pref[i + 1] = pref[i] + arr[i];
		opt[i][i] = i;
	}

	// Iterating through all sub-arrays
	// of length 2 or greater
	for (int i = N - 2; i >= 0; i--) {
		for (int j = i + 1; j < N; j++) {

			// Cost function = sum of
			// all elements in the sub-array
			int cost = pref[j + 1] - pref[i];
			int mn = INT_MAX;
			for (int k = opt[i][j - 1];
				k <= min(j - 1, opt[i + 1][j]);
				k++) {
				if (mn >= dp[i][k]
					+ dp[k + 1][j] + cost) {

					// Updating opt table
					opt[i][j] = k;

					// Updating minimum cost
					mn = dp[i][k]
						+ dp[k + 1][j] + cost;
				}
			}

			// dp transition
			dp[i][j] = mn;
		}
	}
	return dp[0][N - 1];
}

// Driver code
int main()
{
	int arr[] = { 3, 4, 2, 1, 7 };
	int N = sizeof(arr) / sizeof(arr[0]);

	// Function call
	cout << minCost(arr, N);
	return 0;
}
