class Solution {
public:
    bool fun(string &s, string &t, int i, int j, vector<vector<int>>&dp){
        if(i<0 && j<0){ // Both strings finished
            return true;
        }
        if(j<0){ // If pattern finishes
            return false;
        }
        if(i<0){ // If string finshed,
            while(j>=0){
                if(t[j]!='*'){
                    return false;
                }
                j--;
            }
            return true;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }

        // If mismatch
        if(s[i]!=t[j]){
            if(t[j]=='.'){ // If pattern has question mark
            // abc a?c
                return fun(s,t,i-1,j-1,dp);
            }
            else if(t[j]=='*'){ // If pattern has star abcd a*d
                bool assumeEmpty = fun(s,t,i,j-1,dp);
                bool matchOne = fun(s,t, i-1,j,dp);
                return dp[i][j] = assumeEmpty || matchOne;
            }

            // Both are charachters
            return false;
        }
        else{
            return dp[i][j] = fun(s,t,i-1,j-1,dp);
        }
    }
    bool isMatch(string s, string p) {
        vector<vector<int>>dp(s.length()+1, vector<int>(p.length()+1,-1));
        return fun(s,p, s.length()-1, p.length()-1,dp);
    }
};