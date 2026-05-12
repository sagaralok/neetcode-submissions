class Solution {
public:
    bool fun(vector<int>&nums,int sum,int i,vector<vector<int>>&dp){
        if(i<=0){
            return false;
        }
        if(sum==0){
            return true;
        }
        if(dp[i][sum]!=-1){
            return dp[i][sum];
        }
        if(nums[i-1]<=sum){
            int take = fun(nums,sum-nums[i-1],i-1,dp);
            int notTake = fun(nums,sum,i-1,dp);
            return dp[i][sum] = take || notTake;
        }
        else{
            return dp[i][sum] = fun(nums,sum,i-1,dp);
        }
    }
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(auto x:nums){
            sum+=x;
        }
        if(sum%2!=0){
            return false;
        }
        int sz = nums.size();
        vector<vector<int>>dp(sz+1,vector<int>(sum/2+1,-1));
        return fun(nums, sum/2,nums.size(),dp);
    }
};
