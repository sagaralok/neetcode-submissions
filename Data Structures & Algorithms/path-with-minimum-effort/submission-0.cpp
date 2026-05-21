#define pairs pair<int,pair<int,int>>
class Solution {
public:

    int xDir[4] = {-1,0,1,0};
    int yDir[4] = {0,1,0,-1};

    bool isValid(int x, int y, int n, int m ){
        if((x>=0 && x<n) && (y>=0 && y<m)){
            return true;
        }
        return false;
    }
    int minimumEffortPath(vector<vector<int>>& arr) {
        int n = arr.size(), m = arr[0].size();


        vector<vector<int>>path(n,vector<int>(m,INT_MAX));

        priority_queue<pairs, vector<pairs>, greater<pairs>>qu;
        
        path[0][0]=0;
        qu.push({0,{0,0}});

        while(!qu.empty()){
            int maxTillnow = qu.top().first;
            int row = qu.top().second.first;
            int col = qu.top().second.second;
            qu.pop();

            if(row == n-1 && col == m-1){
                return path[n-1][m-1];
            }

            for(int i = 0;i<4;i++){
                int newX = row+xDir[i];
                int newY = col+ yDir[i];

                if(isValid(newX, newY, n, m)){
                    int diff = abs(arr[newX][newY] - arr[row][col]); 

                    int maxEffort = max(diff, maxTillnow);

                    if(maxEffort < path[newX][newY]){ // Consider
                        path[newX][newY] = maxEffort;
                        qu.push({maxEffort,{newX,newY}});
                    }
                }
            }
        }
        return -1;
    }
};