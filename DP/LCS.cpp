class Solution
{
public:
    // Memoization
    //  int fn(string &a,string&b,int i,int j,vector<vector<int>>&dp){
    //      if(i<0||j<0) return 0;
    //      if(dp[i][j]!=-1) return dp[i][j];
    //      if(a[i]==b[j]){
    //          return dp[i][j]=1+fn(a,b,i-1,j-1,dp);
    //      }
    //      return dp[i][j]=max(fn(a,b,i,j-1,dp),fn(a,b,i-1,j,dp));
    //  }

    // Space Optimization
    int longestCommonSubsequence(string text1, string text2)
    {
        int a = text1.size(), b = text2.size();
        vector<int> cur(b + 1, 0), prev(b + 1, 0);
        // index shifted here
        for (int i = 1; i <= a; i++)
        {
            for (int j = 1; j <= b; j++)
            {
                if (text1[i - 1] == text2[j - 1])
                {
                    cur[j] = 1 + prev[j - 1];
                }
                else
                {
                    cur[j] = max(prev[j], cur[j - 1]);
                }
            }
            prev = cur;
        }
        return prev[b];
    }

    // Tabulation
    //  int longestCommonSubsequence(string text1, string text2) {
    //      int a=text1.size(),b=text2.size();
    //      vector<vector<int>>dp(a+1,vector<int>(b+1,0));
    //      // return fn(text1,text2,a-1,b-1,dp);
    //      //index shifted here
    //      for(int i=1;i<=a;i++){
    //          for(int j=1;j<=b;j++){
    //              if(text1[i-1]==text2[j-1]){
    //                  dp[i][j]=1+dp[i-1][j-1];
    //              }
    //              else{
    //                  dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
    //              }
    //          }
    //      }
    //      return dp[a][b];
    //  }
};