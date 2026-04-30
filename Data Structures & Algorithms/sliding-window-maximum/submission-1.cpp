class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int>ans;

        // maintaining a max queue

        deque<int>dq;
        for(int i = 0;i<k;i++){
            if(dq.size()==0){
                dq.push_back(i);
            }
            else{
                while(!dq.empty() && nums[dq.back()]<nums[i]){
                    dq.pop_back();
                }
                dq.push_back(i);
            }
        }
        ans.push_back(nums[dq.front()]);

        for(int i = k;i<nums.size();i++){

            // Remove the element which is out of window
            int toRemoveIndex = i-k;
            if(toRemoveIndex==dq.front()){
                dq.pop_front();
            }

            while(!dq.empty() && nums[dq.back()]<nums[i]){
                dq.pop_back();
            }
            dq.push_back(i);
            ans.push_back(nums[dq.front()]);
        }
        return ans;
    }
};
