class Solution {
public:
    void fun(vector<int>&nums, int ind, vector<int>&prev, vector<vector<int>>&ans){
        if(ind==nums.size()){
            ans.push_back(prev);
            return;
        }
        prev.push_back(nums[ind]);
        fun(nums, ind+1, prev, ans);

        prev.pop_back();
        fun(nums,ind+1, prev, ans);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>prev;
        // ans.push_back(prev);
        fun(nums, 0, prev, ans);
        return ans;
    }
};
