class Solution {
public:

    void generate(string str, vector<string>&ans, int leftCount, int rightCount){
        if(leftCount==0 && rightCount==0 ){
            ans.push_back(str);
            return;
        }
        // "("  Can be used: untill leftCount>0
        if(leftCount>0){
            generate(str+'(', ans, leftCount-1, rightCount);
        }

        if(leftCount<rightCount){
            generate(str+')', ans, leftCount, rightCount-1);
        }

    }
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        string s = "";
        generate(s, ans, n, n);
        return ans;
    }
};
