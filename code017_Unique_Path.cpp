Brute---------------------->>>>
  (Recursive) 
  Time --------------->>> O()
  Space --------------->>> O()

    #include <bits/stdc++.h> 
    int uniquePaths(int m, int n) {
    	int path = 0;
    
    	if(m == 1) return 1;
    	if(n==1) return 1;
    
    
    	int up =  uniquePaths(m-1,n);
    	int down = uniquePaths(m,n-1);
    
    	return up + down;
    }




DP Solution ------------------>>>
    Time ----------------->>> O(N2)
    Space---------------->>>> O(N2)


    #include <bits/stdc++.h> 
    int uniquePaths(int m, int n) {
    	// The basoc Recursive Approach will give TLE
    	// So We have use Little Essesnce of Dp
    
    	vector<vector<int>>dp(m,vector<int>(n,1));
    	for(int i=1;i<m;i++)
    	{
    		for(int j=1;j<n;j++)
    		{
    			dp[i][j] = dp[i][j-1] + dp[i-1][j];
    		}
    	}
    	return dp[m-1][n-1];	
}
