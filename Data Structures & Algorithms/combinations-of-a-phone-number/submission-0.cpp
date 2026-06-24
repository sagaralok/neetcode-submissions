class Solution {
public:
    vector<string>charss = {"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};


    void combinations(string digits, int ind, vector<string>&ans, string prev){

        if(ind==digits.size()){
            ans.push_back(prev);
            return;
        }

        // Iterate the current available charachters -> chars[ind-2];

        string currentChars = charss[digits[ind] - '2'];

        for(int i = 0;i<currentChars.length();i++){
            combinations(digits, ind+1,ans, prev+currentChars[i]);
        }
    }    
    vector<string> letterCombinations(string digits) {
        vector<string>ans;
        if(digits.length()==0){
            return ans;
        }
        combinations(digits,0, ans,"");
        return ans;
    }
};
