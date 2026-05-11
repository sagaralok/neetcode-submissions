class Solution {  
public:
    bool fun(string s, int ind, int count, vector<vector<int>>&dp){
        if(count<0){
            return false;
        }
        if(ind==s.length()){
            return (count == 0);
        }

        if(dp[ind][count]!=-1){
            return dp[ind][count];
        }

        if(s[ind]=='('){
            return dp[ind][count] = fun(s,ind+1, count+1,dp);
        }
        else if(s[ind]==')'){
            return dp[ind][count]= fun(s,ind+1, count-1,dp);
        }
        return dp[ind][count] = (fun(s,ind+1, count,dp) || fun(s,ind+1,count+1,dp) || fun(s,ind+1,count-1,dp));
    }
    bool checkValidString(string s) {
        //your code goes here
        // vector<vector<int>>dp(s.length(), vector<int>(s.length()+1,-1));
        // return fun(s,0,0,dp);

        int low = 0, high = 0;

        int i = 0;
        while(i<s.length()){
            if(s[i]=='('){
                low++;
                high++;
            }
            else if(s[i]==')'){
                low--;
                high--;
            }
            else{ // Star --> left count is 1, after star, 0,1,2
                low--;
                high++;
            }
            if(high<0){ // No left bracket is remaining
                return false;
            }
            low = max(0,low);
            i++;
        }
        return low==0;
    }

};