class Solution {
public:

    void subsets(vector<int>&arr, int ind, vector<vector<int>>&ans, vector<int>&prev){

        if(ind==arr.size()){
            ans.push_back(prev);
            return;
        }

        // Take
        prev.push_back(arr[ind]);
        subsets(arr, ind+1, ans, prev);

        // NotTake
        prev.pop_back();

        int next = ind+1;
        while(next<arr.size() && arr[next]==arr[ind]){
            next++;
        }
        subsets(arr, next, ans, prev);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end()); // 1 1 2
        vector<vector<int>>ans;
        vector<int>prev;
        subsets(nums, 0, ans, prev);
        return ans;
    }
};
