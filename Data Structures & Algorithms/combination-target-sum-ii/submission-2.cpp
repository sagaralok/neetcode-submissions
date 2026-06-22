class Solution {
public:
    void solve(vector<int>&arr, int target, vector<int>&prev, vector<vector<int>>&ans, int ind){
        if(target==0){
            ans.push_back(prev);
            return;
        }
        if(ind==arr.size() || target<0){
            return;
        }
        // Take
        prev.push_back(arr[ind]);
        solve(arr, target-arr[ind], prev, ans, ind+1);
        // Not Take

        int next = ind+1;
        while(next < arr.size() && arr[next]==arr[ind]){
            next++;
        }
        prev.pop_back();
        solve(arr, target, prev, ans, next);

    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>>ans;
        vector<int>prev;
        solve(candidates, target, prev, ans,0);
        return ans;
    }
};
