class Solution {
public:
    int fun(vector<int>&coins, int amount, int ind){
        if(amount==0){
            return 0;
        }
        if(amount<0 || ind>=coins.size()){
            return 1e9;
        }
        int take = 1+fun(coins,amount-coins[ind], ind);
        int notTake = fun(coins,amount,ind+1);
        return min(take,notTake);
    }
    int coinChange(vector<int>& coins, int amount) {
        int res = fun(coins,amount,0);
        return res==1e9 ? -1:res ;
    }
};
