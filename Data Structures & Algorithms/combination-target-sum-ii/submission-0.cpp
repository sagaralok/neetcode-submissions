class Solution {
public:
    void solve(vector<int>&arr, int target, vector<int>&prev, set<vector<int>>&st, int ind){
        if(target==0){
            st.insert(prev);
            return;
        }
        if(ind==arr.size() || target<0){
            return;
        }
        // Take
        prev.push_back(arr[ind]);
        solve(arr, target-arr[ind], prev, st, ind+1);
        // Not Take
        prev.pop_back();
        solve(arr, target, prev, st, ind+1);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        set<vector<int>>st;
        vector<int>prev;
        solve(candidates, target, prev, st,0);
        vector<vector<int>> ans(st.begin(), st.end());
        return ans;
    }
};
