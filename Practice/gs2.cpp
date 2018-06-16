if(n==1) return 1;
    if(n==0) return 0;
    if(n==2) return 2;
    if(n<0) return 0;
    
    n+=1;
    if(dp[n] != 0) return dp[n];
    long ans = countSteps(n-1) + countSteps(n-2) + countSteps(n-3);
    dp[n-1] = ans;