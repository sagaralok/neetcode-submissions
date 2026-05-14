class Solution {
public:

    void dfs(int node, vector<int>adj[], vector<int>&vis){
        vis[node]=1;
        for(auto x:adj[node]){
            if(vis[x]==0){
                dfs(x,adj,vis);
            }
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        int ans = 0;

        vector<int> adj[n+1];

        for(int i = 0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }

        vector<int>vis(n+1,0);

        for(int i = 0;i<n;i++){
            if(vis[i]==0){
                dfs(i,adj,vis);
                ans++;
            }
        }

        return ans;
    }
};
