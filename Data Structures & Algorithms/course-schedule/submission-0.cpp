class Solution{
public:
    bool canFinish(int N, vector<vector<int>> arr) {
        vector<int>inDegree(N,0);

        vector<int>adj[N];

        for(int i = 0;i<arr.size();i++){
            inDegree[arr[i][0]]++;
            adj[arr[i][1]].push_back(arr[i][0]);
        }
        queue<int>q;
        vector<int>ans;


        for(int i = 0;i<N;i++){
            if(inDegree[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int top = q.front();
            q.pop();
            ans.push_back(top);
            for(auto x:adj[top]){
                inDegree[x]--;
                if(inDegree[x]==0){
                    q.push(x);
                }
            }
        }
        if(ans.size()==N){
            return true;
        }
        return false;
    }
};