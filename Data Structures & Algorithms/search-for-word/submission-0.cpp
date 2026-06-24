class Solution {
public:

    int xDirection[4] = {-1,0,1,0};
    int yDirection[4] = {0,1,0,-1};

    bool isValid(int x, int y, int n, int m){
        if((x>=0 && x<n) && (y>=0 && y<m)){
            return true;
        }
        return false;
    }
    bool dfs(vector<vector<char>>&board, int x, int y, vector<vector<int>>&vis, int ind, string &word){
        vis[x][y]=1;
        // Traverse in all 4 direction
        if(ind==word.size()){
            return true;
        }
        bool ans = false;
        for(int i = 0;i<4;i++){
            int newX = x+xDirection[i];
            int newY = y+yDirection[i];
            if(isValid(newX, newY, board.size(), board[0].size()) && word[ind]==board[newX][newY] 
                && vis[newX][newY]==0){
                ans = ans || dfs(board, newX, newY, vis, ind+1, word);
            }
        }
        return ans;
    }
    bool exist(vector<vector<char>>& board, string word) {
        bool ans = false;
        vector<vector<int>>vis(board.size(), vector<int>(board[0].size(),0));

        for(int i = 0;i<board.size();i++){
            for(int j = 0;j<board[i].size();j++){
                if(board[i][j]==word[0]){
                    ans = ans || dfs(board, i, j, vis, 1, word);
                }
            }
        }
        return ans;
    }
};
