class Solution {
public:

    int fun(vector<int>&coins, int amount, int ind, vector<vector<int>>&dp){
        if(amount==0){
            return 1;
        }
        if(amount<0 || ind>=coins.size()){
            return 0;
        }
        if(dp[amount][ind]!=-1){
            return dp[amount][ind];
        }
        int take = fun(coins,amount-coins[ind],ind,dp);
        int notTake = fun(coins,amount,ind+1,dp);
        return dp[amount][ind] = take+notTake;   
    }
    int change(int amount, vector<int>& coins) {
        vector<vector<int>>dp(amount+1,vector<int>(coins.size()+1,-1));
        return fun(coins,amount,0,dp);
    }
};
