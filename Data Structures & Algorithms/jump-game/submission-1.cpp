class Solution {
public:
    bool canJump(vector<int>& nums) {
        bool ans = true;

        int reach = nums[0];
        int i = 1;

        while(i<nums.size() && reach>0){
            reach--;
            reach = max(reach,nums[i]);
            i++;
        }
        if(i!=nums.size()){
            ans = false;
        } 

        return ans;
    }
};
