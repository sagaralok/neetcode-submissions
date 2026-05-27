class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        string ans = "";

        vector<int> adj[26];
        vector<int> inDegree(26,0);
        vector<bool> exists(26,false);

        // Mark existing characters
        for(auto word : words){
            for(char c : word){
                exists[c-'a'] = true;
            }
        }
        string prev = words[0];
        for(int i = 1; i < words.size(); i++){
            string current = words[i];
            int x = 0, y = 0;
            bool foundMismatch = false;
            while(x < prev.length() && y < current.length()){
                if(prev[x] != current[y]){
                    foundMismatch = true;
                    adj[prev[x]-'a'].push_back(current[y]-'a');
                    break;
                }
                x++;y++;
            }

        // Invalid prefix case
        // if(!foundMismatch && prev.length() > current.length()){
        //     return "";
        // }
            prev = current;
        }

        // Calculate indegree
        for(int i = 0; i < 26; i++){
            for(auto x : adj[i]){
                inDegree[x]++;
            }
        }

        // Kahn's algo
        queue<int>q;
        for(int i = 0;i<26;i++){
            if(inDegree[i]==0 && exists[i]){
                q.push(i);
            }
        }

        while(!q.empty()){
            int current = q.front();
            q.pop();
            ans+= char(current+'a');
            for(auto x:adj[current]){
                inDegree[x]--;
                if(inDegree[x]==0){
                    q.push(x);
                }
            }
        }

        // Check cycle
        int charCount = 0;
        for(int i = 0;i<exists.size();i++){
            if(exists[i]){
                charCount++;
            }
        }
        if(ans.length()!=charCount){
            return "";
        }
        return ans;
    }
};
