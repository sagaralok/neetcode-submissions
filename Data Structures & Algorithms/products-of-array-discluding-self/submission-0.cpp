class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int>ans(nums.size());
        int n = nums.size();
        int prefix = 1;
        for(int i = 0;i<n;i++){ // Prefix product
            ans[i]=prefix;
            prefix = prefix*nums[i];
        }

        prefix = 1;
        for(int i = n-1;i>=0;i--){
            ans[i]=prefix*ans[i];
            prefix = prefix*nums[i];
        }
        return ans;
    }
};