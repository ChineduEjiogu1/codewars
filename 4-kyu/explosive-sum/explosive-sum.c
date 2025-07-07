unsigned long long exp_sum(unsigned n) 
{
    //  <----  hajime!
    unsigned long long dp[n+1][n+1];
  
    for (int j = 0; j <= n; j++) 
    {
        dp[0][j] = 1;
    }
  
    for (int i = 1; i <= n; i++) 
    {
        dp[i][0] = 0;
    }
  
    for (int j = 1; j <= n; j++)
    { 
        for (int i = 0; i <= n; i++)
        {     
            if (i >= j) 
            {
                dp[i][j] = dp[i][j-1] + dp[i-j][j];
              
            } else {
              
                dp[i][j] = dp[i][j-1];
            }
        }
    }
​
    return dp[n][n];
}