class Solution {
public:

    void fun(vector<int>&arr, int target, vector<vector<int>>&ans, vector<int>&prev, int ind){
        if(target==0){
            ans.push_back(prev);
            return;
        }
        if(ind >= arr.size() || target<0){
            return;
        }

        // Take ?
        prev.push_back(arr[ind]);
        fun(arr,target - arr[ind], ans, prev, ind);

        // Not Take
        prev.pop_back();
        fun(arr, target, ans, prev, ind+1);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>prev;
        fun(candidates, target, ans, prev, 0);
        return ans;
    }
};