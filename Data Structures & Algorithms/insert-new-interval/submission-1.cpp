class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        
        // Discard the smaller intervals, means which are lesser then first new number (6,8) -> (1,2) (3,4)
        int i = 0;
        int n = intervals.size();
        vector<vector<int>>ans;
        int start = newInterval[0], end = newInterval[1];

        while(i<n && intervals[i][1]<newInterval[0]){
            ans.push_back(intervals[i]);
            i++;
        }
        // Add first number (3,10) -> (1,2), (6,7), (8,9) (10,13)
        if(i<n){
            start = min(intervals[i][0],start);
        }


        // Add second number: (3,4) -> (1,2) (6,8) || (1,2) (4,6)
        while(i<n &&end>=intervals[i][0]){
            end = max(end, intervals[i][1]);
            i++;
        }
        ans.push_back({start,end});

        // Push leftover elements
        while(i<n){
            ans.push_back(intervals[i]);
            i++;
        }
        return ans;
    }
};
