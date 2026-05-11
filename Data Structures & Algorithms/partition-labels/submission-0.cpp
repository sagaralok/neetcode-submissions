class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int>ans;
        vector<int>mp(26,-1);
        for(int i = 0;i<s.length();i++){
            mp[s[i]-'a']=i;
        }

        for(int i = 0;i<26;i++){
            cout<<mp[i]<<" ";
        }
        cout<<endl;


        int ind = 0;
        while(ind<s.length()){
            int maxRange = mp[s[ind]-'a']; // Max index of currentIndex;

            cout<<s[ind]<<" "<<maxRange<<endl;

            int j = ind;
            while(j<maxRange){
                int subStringMaxRange = mp[s[j]-'a'];
                if(subStringMaxRange>maxRange){
                    maxRange = subStringMaxRange;
                }
                j++;
            }
            ans.push_back(j-ind+1);
            ind = j+1;
        }
        return ans;
    }
};
