class Solution {
public:

    // Take | NotTake
    int maxCombination(vector<int>&arr, int target, int ind, vector<vector<int>>&dp){

        if(ind>=arr.size() || target<0){
            return 0;
        }

        if(target == 0){
            return 1;
        }
        if(dp[ind][target]!=-1){
            return dp[ind][target];
        }
        // Take
        int take = maxCombination(arr, target-arr[ind], ind,dp);
        // NotTake
        int notTake = maxCombination(arr, target, ind+1,dp);

        return dp[ind][target] = take+notTake;

    }
    int change(int amount, vector<int>& coins) {
        vector<vector<int>>dp(coins.size(), vector<int>(amount+1,-1));
        return maxCombination(coins, amount,0,dp);
    }
};
