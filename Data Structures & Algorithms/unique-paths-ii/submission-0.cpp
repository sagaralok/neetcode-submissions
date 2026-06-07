class Solution {
public:

    int isValid(int x, int y, int n, int m, vector<vector<int>>&arr){
        if((x>=0 && x<n) && (y>=0 && y<m) && arr[x][y]==0){
            return true;
        }
        return false;
    }


    int uniquePath(vector<vector<int>>&matrix, int x, int y, vector<vector<int>>&dp){
        if(x==matrix.size()-1 && y == matrix[0].size()-1){
            return 1;
        }
        if(dp[x][y]!=-1){
            return dp[x][y];
        }
        // At every valid index we have two options, goDown / GoRight
        int right = 0 , left = 0;
        if(isValid(x,y+1,matrix.size(),matrix[0].size(),matrix)){
            right = uniquePath(matrix, x, y+1,dp);
        }
        if(isValid(x+1,y,matrix.size(),matrix[0].size(),matrix)){
            left = uniquePath(matrix, x+1, y,dp);
        }
        return dp[x][y] = right+left;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        if(matrix[n-1][m-1]==1 || matrix[0][0]==1){
            return 0;
        }
        vector<vector<int>>dp(n+1, vector<int>(m+1,-1));
        return uniquePath(matrix, 0,0, dp);
    }
};