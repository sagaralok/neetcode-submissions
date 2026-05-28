class Solution {
public:
    int maxProfit(vector<int> arr){
        int n = arr.size();

        vector<vector<int>>dp(n+1,vector<int>(2,0));

        for(int ind = n-1;ind>=0;ind--){
            for(int bought = 0;bought<=1;bought++){
                if(bought==1){
                    int sell = arr[ind] + dp[ind+1][0];
                    int notSell = dp[ind+1][1];
                    dp[ind][bought] = max(sell,notSell);
                }
                else{
                    int buy = -arr[ind] + dp[ind+1][1];
                    int notBuy = dp[ind+1][0];
                    dp[ind][bought] = max(buy, notBuy);
                }
            }
        }
        return dp[0][0];
    }
};