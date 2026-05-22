class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans;
        int count1 = 0, count2 = 0, element1 = INT_MAX, element2 = INT_MAX;
        for(int i = 0;i<n;i++){
            if(count1 == 0 && element2!=nums[i]){
                element1 = nums[i];
                count1++;
            }
            else if(count2==0 && element1!=nums[i]){
                element2 = nums[i];
                count2++;
            }
            else if(nums[i]==element1){
                count1++;
            }
            else if(nums[i]==element2){
                count2++;
            }
            else{
                count1--;
                count2--;
            }
        }
        
        int cnt1 = 0, cnt2 =0;
        for(int i = 0;i<n;i++){
            if(nums[i]==element1){
                cnt1++;
            }
            if(nums[i]==element2){
                cnt2++;
            }
        }
        if(cnt1>(n/3)){
            ans.push_back(element1);
        }
        if(cnt2>(n/3) && element2!=element1){
            ans.push_back(element2);
        }
        return ans;
    }
};