class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0){
            return 0;
        }
        unordered_map<int,int>mp;

        int res = 1;
        for(auto x:nums){
            mp[x]=1;
        }
        for(auto x:mp){
            if(mp.find(x.first-1)==mp.end()){ // no smaller element is there
                int count = 1;
                int current = x.first;

                while(mp.find(current+1)!=mp.end()){
                    count++;
                    current = current+1;
                }
                res = max(res,count);
            }

        }
        return res;
    }
};
