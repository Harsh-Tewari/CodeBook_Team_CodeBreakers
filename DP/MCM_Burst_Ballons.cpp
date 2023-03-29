class Solution
{
public:
    int dp[300][300];
    int fn(int i, int j, vector<int> &v)
    {
        if (i > j)
            return 0;
        if (dp[i - 1][j - 1] != -1)
            return dp[i - 1][j - 1];
        int ans = 0;
        for (int k = i; k <= j; k++)
        {
            int coins = v[i - 1] * v[k] * v[j + 1] + fn(i, k - 1, v) + fn(k + 1, j, v);
            // go in reverse dirn
            // jo last me aaya wo pehle burst hua hoga
            //  kyuki agar i,j aaya hai toh i-1 hi burst hua h pehle and neghbour hai
            ans = max(ans, coins);
        }
        return dp[i - 1][j - 1] = ans;
    }
    int maxCoins(vector<int> &nums)
    {
        memset(dp, -1, sizeof(dp));
        vector<int> v = nums;
        v.push_back(1);
        v.insert(v.begin(), 1);
        return fn(1, nums.size(), v);
    }
};