class Solution {
public:
    int fun(string s1, string s2, int x, int y, vector<vector<int>>&dp){
        if(x>=s1.length() || y>=s2.length()){
            return 0;
        }
        if(dp[x][y]!=-1){
            return dp[x][y];
        }
        // Match
        if(s1[x]==s2[y]){
            return dp[x][y]= 1+fun(s1,s2,x+1,y+1,dp);
        }
        else{ // Mismatch
            return dp[x][y] = max(fun(s1,s2,x+1,y,dp),fun(s1,s2,x,y+1,dp));
        }
    }
    int longestCommonSubsequence(string text1, string text2) {
        // vector<vector<int>>dp(text1.size(), vector<int>(text2.size(),0));
        // return fun(text1, text2, 0,0,dp);
        int n = text1.size();
        int m = text2.size();

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        for(int i = 1;i<=text1.size();i++){
            for(int j = 1;j<=text2.size();j++){
                if(text1[i-1]==text2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else{
                    dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        return dp[n][m];
    }
};
