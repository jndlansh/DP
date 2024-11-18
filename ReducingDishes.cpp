class Solution {
        //JUST LIKE KNAPSACK
private:
    int solveMem(vector<int>& satisfaction, int index, int time, vector<vector<int>>& dp){
        int n=satisfaction.size();
        if(index==n){
            return 0;
        }
        if(dp[index][time]!=-1)
            return dp[index][time];
        
        int include = satisfaction[index]*(time+1) + solveMem(satisfaction, index+1, time+1, dp);
        int exclude = 0 + solveMem(satisfaction, index+1, time, dp);

        return dp[index][time]=max(include, exclude);

    }
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        vector<vector<int>>dp(satisfaction.size(), vector<int>(satisfaction.size(), -1));
        sort(satisfaction.begin(), satisfaction.end());
        return solveMem(satisfaction, 0, 0, dp);        
    }
};
