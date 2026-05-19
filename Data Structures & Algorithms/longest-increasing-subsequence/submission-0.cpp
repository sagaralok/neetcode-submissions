class Solution {
public:
    int fun(vector<int>&arr, int ind, int prevInd,vector<vector<int>> &dp){
        if(ind>=arr.size()){
            return 0;
        }
        if(dp[ind][prevInd+1]!=-1){
            return dp[ind][prevInd+1];
        }

        // int take
        if(prevInd==-1 || arr[ind]>arr[prevInd]){

            int take = 1+fun(arr, ind+1, ind,dp);
            int notTake = fun(arr, ind+1,prevInd,dp);
            return dp[ind][prevInd+1] = max(take, notTake);
        }
        return dp[ind][prevInd+1] = fun(arr, ind+1, prevInd,dp);

        // int notTake
    }
    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>> dp(nums.size(), vector<int>(nums.size(),-1));
        return fun(nums,0, -1,dp);
    }    
};