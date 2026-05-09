class Solution {
public:
    bool canJump(vector<int>& nums) {
        int reach = nums[0];
        int i = 1;

        while(i<nums.size() && reach>0){
            reach--;
            reach = max(reach,nums[i]);
            i++;
        }
        return i==nums.size();
    }
};
