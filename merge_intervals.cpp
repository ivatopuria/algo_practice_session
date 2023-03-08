class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // intervals = [ [1, 3], [2, 6], [8, 10], [15, 18]]
        // [1 2 3] [2 3 4 5 6]
        // [1 ... 6]
        sort(intervals.begin(), intervals.end());
        int n = intervals.size();
        vector<vector<int>> answer;
        
        int previous_l = intervals[0][0], previous_r = intervals[0][1];
        for(int i = 1 ; i < n ; i++){
            int l = intervals[i][0];
            int r = intervals[i][1];
            if(previous_r >= l){
                previous_r = max(previous_r, r);
            }else{
                answer.push_back({previous_l,previous_r});
                previous_l = l;
                previous_r = r;
            }
        }

        answer.push_back({previous_l,previous_r});
        return answer;
    }
};