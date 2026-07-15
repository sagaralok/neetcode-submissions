class Solution {
public:
    int findSum(int ind, int root, int n){
        if(n==0){
            return 0;
        }
        if(n<0 || ind>root){
            return INT_MAX;
        }

        // Take ind
        int take = INT_MAX;
        int sub = findSum(ind, root, n - ind*ind);

        if(sub != INT_MAX) {
            take = 1 + sub;
        }


        // not Take
        int notTake = findSum(ind+1,root, n);

        return min(take, notTake);

    }
    int numSquares(int n) {
        return findSum(1,sqrt(n), n);
    }
};