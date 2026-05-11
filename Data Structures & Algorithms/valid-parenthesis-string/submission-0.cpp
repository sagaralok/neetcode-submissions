class Solution {
public:
    bool checkValidString(string s) {
        int starCount = 0, leftCount = 0;
        for(int i = 0;i<s.length();i++){
            if(s[i]=='('){
                leftCount++;
            }
            else if(s[i]=='*'){
                starCount++;
            }
            else{
                if(leftCount>0){
                    leftCount--;
                }
                else if(starCount>0){
                    starCount--;
                }
                else{
                    return false;
                }
            }
        }
        if(leftCount>starCount){
            return false;
        }
        return true;
    }
};
