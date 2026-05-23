class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans = INT_MIN;
        int n = nums.size();
        int prefix = 1;
        int postfix = 1;

        for(int i=0;i<n;i++) {
            if(prefix == 0){
                prefix = 1;
            }
            if(postfix==0){
                postfix=1;
            }
            prefix *= nums[i];
            postfix *= nums[n-1-i];
            ans = max(ans, max(postfix,prefix));
        }

        return ans;
    }
};