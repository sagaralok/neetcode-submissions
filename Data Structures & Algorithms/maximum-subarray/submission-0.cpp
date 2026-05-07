class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        int ans = nums[0];

        int prevSum = nums[0];

        for(int i = 1;i<nums.size();i++){
            int currentMax = max(prevSum+nums[i],nums[i]);
            ans = max(currentMax,ans);
            prevSum = currentMax;
        }
        return ans;

    }
};
