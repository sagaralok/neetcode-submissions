class Solution {
public:

    int xDirection[4] = {-1,0, 1, 0};
    int yDirection[4] = {0, 1, 0,-1};

    bool isValid(int x, int y, int n, int m){
        if((x>=0 && x<n) && (y>=0 && y<m)){
            return true;
        }
        return false;
    }

    void dfs(vector<vector<int>>&vis, vector<vector<char>>&grid, int x, int y){
        vis[x][y]=1;

        for(int i = 0;i<4;i++){
            int newX = x+xDirection[i];
            int newY = y+yDirection[i];
            if(isValid(newX,newY, grid.size(), grid[0].size()) && grid[newX][newY]=='1' 
                && vis[newX][newY] ==0){
                dfs(vis,grid,newX,newY);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        
        int ans = 0;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>vis(n+1,vector<int>(m+1,0));
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(grid[i][j] == '1' && vis[i][j]==0){
                    ans++;
                    dfs(vis, grid, i, j);
                }
            }
        }

        return ans;
    }
};
