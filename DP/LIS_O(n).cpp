int lengthOfLIS(vector<int> &v)
{
    int n = v.size();

    /////////O(n) space soln/////////////////

    vector<int> dp(n, 1); // kyuki har element khud size 1 ka lis h
    int maxi = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (v[i] > v[j])
                dp[i] = max(dp[i], 1 + dp[j]);
        }
        maxi = max(maxi, dp[i]);
    }
    return maxi;
}