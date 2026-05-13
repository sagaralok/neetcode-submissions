class Solution {
public:
    int fun(string s, string t, int i, int j){
        if(j == t.length()){ // We found a subsequence
            return 1;
        }
        if(i == s.length()){
            return 0; // No subsequence found
        }


        // If char matches
        if(s[i]==t[j]){
            int consider = fun(s,t,i+1,j+1);
            int notConsider = fun(s,t,i+1,j);
            // if(consider == -1 && notConsider == -1){
            //     return -1;
            // }
            // return max(consider, notConsider)+1;
            return consider + notConsider;
        }

        // If char doesn't match
        return fun(s,t,i+1,j);
    }
    int numDistinct(string s, string t) {
        // If charachter match: ccat ca
        // a: Consider this as one of the subsequence
        // b: Not consider as the subsequence

        // If don't match:  cat dog -> return 0; Move first
        return fun(s,t,0,0);
    }
};
