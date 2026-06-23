class Solution {
public:


    void fun(vector<int>& arr, vector<int>& prev, vector<vector<int>>& ans) {
        if (arr.empty()) {
            ans.push_back(prev);
            return;
        }

        for (int i = 0; i < arr.size(); i++) {

            int num = arr[i];

            prev.push_back(arr[i]);
            arr.erase(arr.begin() + i);

            // Explore
            fun(arr, prev, ans);

            // Undo
            arr.insert(arr.begin() + i, num);
            prev.pop_back();
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>prev;
        fun(nums, prev, ans);
        return ans;
    }
};
