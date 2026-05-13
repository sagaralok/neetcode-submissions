class Solution {
public:
    int fun(string s, string t, int i, int j, vector<vector<int>>&dp){
        if(j == t.length()){ // We found a subsequence
            return 1;
        }
        if(i == s.length()){
            return 0; // No subsequence found
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }


        // If char matches
        if(s[i]==t[j]){
            int consider = fun(s,t,i+1,j+1,dp);
            int notConsider = fun(s,t,i+1,j,dp);
            // if(consider == -1 && notConsider == -1){
            //     return -1;
            // }
            // return max(consider, notConsider)+1;
            return dp[i][j] = consider + notConsider;
        }

        // If char doesn't match
        return dp[i][j] = fun(s,t,i+1,j,dp);
    }
    int numDistinct(string s, string t) {
        // If charachter match: ccat ca
        // a: Consider this as one of the subsequence
        // b: Not consider as the subsequence

        // If don't match:  cat dog -> return 0; Move first
        vector<vector<int>>dp(s.length()+1, vector<int>(t.length()+1,-1));
        return fun(s,t,0,0,dp);
    }
};
