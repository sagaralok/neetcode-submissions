class Solution {
public:


    int xDirection[4] = {-1,0,1,0};
    int yDirection[4] = {0,1,0,-1};

    bool isValid(int x,int y, int n, int m){
        if(x<0 || x>=n || y<0 || y>=m){
            return false;
        }
        return true;
    }

    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();

        int ans = 0;
        vector<vector<int>>vis(n+1,vector<int>(m+1,0));
        queue<pair<int,int>>q;

        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }
            }
        }
        while(!q.empty()){
            int sz = q.size();
            bool changed = false;
            
            for(int i = 0;i<sz;i++){
                pair<int,int> top = q.front();
                q.pop();
                for(int i = 0;i<4;i++){
                    int newX = top.first+ xDirection[i];
                    int newY = top.second+ yDirection[i];

                    if(isValid(newX,newY, n,m) && grid[newX][newY]==1){
                        q.push({newX,newY});
                        grid[newX][newY] = 2;
                        changed = true;

                    }
                }
            }
            if(changed){
                ans++;
            }
        }
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                cout<<grid[i][j]<<" ";
                if(grid[i][j]==1){
                    return -1;
                }
            }
            cout<<endl;
        }
        return ans;
    }
};