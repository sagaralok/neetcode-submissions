class Solution{
public:
    int maxProfit(vector<int> arr){
        int n = arr.size();
        int ans = 0;
        int prev = arr[0];
        for(int i = 1;i<n;i++){
            if(prev<arr[i]){ // Previous is smaller like 5, 10
                ans = max(ans, arr[i]-prev);
            }
            else{
                prev = arr[i];
            }
        }
        return ans;
    }
};

