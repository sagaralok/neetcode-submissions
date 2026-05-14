class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        int ans = 0;
        vector<int>mp(500,0);
        int left = 0;
        for(int i = 0;i<s.length();i++){ // abcabcbb
            mp[s[i]-'a']++;
            while(mp[s[i]-'a']>1){
                mp[s[left]-'a']--;
                left++;
            }
            
            ans = max(ans,i-left+1);
        }
        return ans;
    }
};
