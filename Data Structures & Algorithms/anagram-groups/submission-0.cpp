class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        map<vector<int>, vector<string>> mp;
        for(int i = 0; i < strs.size(); i++) {
            vector<int> v(26, 0);
            string s = strs[i];
            for(int j = 0; j < s.length(); j++) {
                v[s[j] - 'a']++;
            }
            mp[v].push_back(s);
        }
        vector<vector<string>> ans;
        for(auto x : mp) {
            ans.push_back(x.second);
        }
        return ans;
    }
};