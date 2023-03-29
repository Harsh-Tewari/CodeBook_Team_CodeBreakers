class Solution
{
public:
    int dp[100][100];
    int fn(int i, int j, int arr[])
    {
        if (i >= j)
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        int ans = 1e9;
        for (int k = i; k < j; k++)
        {
            int s = arr[i - 1] * arr[k] * arr[j] + fn(i, k, arr) + fn(k + 1, j, arr);
            ans = min(ans, s);
        }
        return dp[i][j] = ans;
    }
    int matrixMultiplication(int N, int arr[])
    {
        memset(dp, -1, sizeof(dp));
        return fn(1, N - 1, arr);
    }
};