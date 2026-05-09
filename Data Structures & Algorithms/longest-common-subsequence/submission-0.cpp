class Solution {
public:
    int fun(string s1, string s2, int x, int y){
        if(x>=s1.length() || y>=s2.length()){
            return 0;
        }

        // Match
        if(s1[x]==s2[y]){
            return 1+fun(s1,s2,x+1,y+1);
        }
        else{ // Mismatch
            return max(fun(s1,s2,x+1,y),fun(s1,s2,x,y+1));
        }
    }
    int longestCommonSubsequence(string text1, string text2) {
        return fun(text1, text2, 0,0);
    }
};
