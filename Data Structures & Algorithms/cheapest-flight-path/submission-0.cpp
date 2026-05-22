# define pairs pair<int,pair<int,int>>
class Solution{
public:
    int findCheapestPrice(int n, vector<vector<int>> &flights,
                       int src, int dst, int k) {
    
        queue<pairs>pq; // <stop, <Node,dist>>
        vector<int>path(n,INT_MAX);

        vector<pair<int,int>> adj[n]; // Connected nodes and distance

        for(int i = 0;i<flights.size();i++){
            adj[flights[i][0]].push_back({flights[i][1], flights[i][2]});
        }
        pq.push({0,{src,0}}); // Pushing the source node
        path[src]=0;
        int ans = INT_MAX;

        while(!pq.empty()){ // {100,{1,1}}
            int stops = pq.front().first;
            int node = pq.front().second.first;
            int distance = pq.front().second.second;
            pq.pop();
            if(stops>k){
                continue;
            }
            for(auto x: adj[node]){
                int adjNode = x.first;
                int edgeWt = x.second;

                if(edgeWt+distance<path[adjNode] && stops<=k){
                    path[adjNode] = distance+edgeWt;
                    pq.push({stops+1,{adjNode,distance+edgeWt}});
                }
            }
        }
        return path[dst] == INT_MAX ? -1 : path[dst];
    }
};
