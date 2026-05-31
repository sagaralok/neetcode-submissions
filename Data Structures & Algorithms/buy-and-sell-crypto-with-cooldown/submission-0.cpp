class Solution {
public:
    int solve(vector<int>&arr, int ind, int bought, vector<vector<int>>&dp){
        if(ind>=arr.size()){
            return 0;
        }
        if(dp[bought][ind]!=-1){
            return dp[bought][ind];
        }
        if(bought==1){ // We previously bought, can sell/ignore
            int sell = arr[ind] + solve(arr, ind+2, 0 , dp);
            int notSell = solve(arr,ind+1,bought,dp);
            return dp[bought][ind] = max(sell, notSell);
        }
        else{ // We haven't bought anything yet, can buy/ignore
            int buy = -arr[ind] + solve(arr,ind+1,1,dp);
            int notBuy = solve(arr,ind+1,bought,dp);
            return dp[bought][ind] = max(buy, notBuy);
        }
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>>dp(2,vector<int>(n+1,-1));
        return solve(prices, 0, 0, dp);

    }
};
