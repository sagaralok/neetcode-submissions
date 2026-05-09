class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if(n%groupSize!=0){
            return false;
        }
        int noOfGroups = n/groupSize;

        // sort(hand.begin(),hand.end());
        map<int,int>mp;

        for(int i = 0;i<n;i++){
            mp[hand[i]]++;
        }

        for(int i = 0;i<noOfGroups;i++){

            int first = mp.begin()->first;
            mp[first]--;
            if(mp[first]==0){
                mp.erase(first);
            }
            for(int j = 0;j<groupSize-1;j++){
                first +=1;
                if(mp.find(first) == mp.end() || mp[first]==0){ // Consecutive not found or it's count is 0
                    return false;
                }
                mp[first]--;
                if(mp[first]==0){
                    mp.erase(first);
                }
            }
        }
        return true;




        // for(int i =0;i<n;i++){

        // }
        // int i = 0;
        // int prevNum = hand[i];
        // while(i<n){
        //     if(hand[i+countOfEach-1]!=prevNum){
        //         return false;
        //     }
        //     i = i+countOfEach;
        //     if(i<n && hand[i] != prevNum+1){
        //         return false;
        //     }
        //     prevNum = hand[i];
        // }
        // return true;
    }
};
