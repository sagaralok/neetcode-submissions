class Solution {
public:

    int fun(vector<int>&coins, int amount, int ind){
        if(amount==0){
            return 1;
        }
        if(amount<0 || ind>=coins.size()){
            return 0;
        }
        int take = fun(coins,amount-coins[ind],ind);
        int notTake = fun(coins,amount,ind+1);
        return take+notTake;   
    }
    int change(int amount, vector<int>& coins) {
        return fun(coins,amount,0);
    }
};
