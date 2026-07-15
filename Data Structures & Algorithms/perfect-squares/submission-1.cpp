class Solution {
public:
    int findSum(int ind, int root, int n, vector<vector<int>>&dp){
        if(n==0){
            return 0;
        }
        if(n<0 || ind>root){
            return INT_MAX;
        }
        if(dp[ind][n]!=-1){
            return dp[ind][n];
        }

        // Take ind
        int take = INT_MAX;
        int sub = findSum(ind, root, n - ind*ind, dp);

        if(sub != INT_MAX) {
            take = 1 + sub;
        }

        // not Take
        int notTake = findSum(ind+1,root, n, dp);

        return dp[ind][n] = min(take, notTake);

    }
    int numSquares(int n) {
        vector<vector<int>>dp(n+1, vector<int>(n+1,-1));
        return findSum(1,sqrt(n), n,dp);
    }
};