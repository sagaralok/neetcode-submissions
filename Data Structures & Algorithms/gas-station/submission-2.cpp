class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int ans = 0, n = gas.size();

        int prevSum = 0, totalSum =0;
        for(int i = 0;i<n;i++){
            int diff = gas[i]-cost[i];

            totalSum+=diff;
            prevSum+=diff;
            
            if(prevSum<0){ // If sum becomes negetive at any point,
                ans = i+1; // Previous is not answer.
                prevSum=0; // We will calculate the prevSum from next index now.
            }
        }
        if(totalSum>=0){
            return ans;
        }
        return -1;
    }
};
