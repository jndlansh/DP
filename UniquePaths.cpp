class Solution {
private:
    int solve(int m, int n, vector<vector<int>>&dp, int row, int col){
        if(row>=m || col>=n)
            return 0;
        if(row==m-1 && col==n-1)
            return 1;
        
        if(dp[row][col]!=-1)
            return dp[row][col];

        return dp[row][col]=solve(m, n, dp, row+1, col)+solve(m, n, dp, row, col+1);        
    }
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m, vector<int>(n, -1));
        return solve(m,n,dp,0,0);
    }
};
