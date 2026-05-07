class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        int ans = nums[0];

        int prevSum = nums[0];

        for(int i = 1;i<nums.size();i++){
            prevSum = max(prevSum+nums[i],nums[i]);
            ans = max(prevSum,ans);
        }
        return ans;

    }
};
