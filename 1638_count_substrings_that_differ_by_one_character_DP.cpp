class Solution {
public:
    string global_s;
    string global_t;
    vector<vector<int>> dp;
    vector<vector<int>> used;
    int rec(int i, int j){
        if(i >= global_s.size()){
            return 0;
        }
        if(j >= global_t.size()){
            return 0;
        }
        if(used[i][j] == 1){
            return dp[i][j];
        }
        used[i][j] = 1;
        if(global_s[i] == global_t[j]){
            dp[i][j] = rec(i + 1, j + 1);
        }else{
            int current_i = i + 1;
            int current_j = j + 1;
            int counter = 1;
            while(true){
                if(current_i == global_s.size()){
                    break;
                }
                if(current_j == global_t.size()){
                    break;
                }
                if(global_s[current_i] != global_t[current_j]){
                    break;
                }
                current_i += 1;
                current_j += 1;
                counter += 1;
            }
            dp[i][j] = counter;
        }
        return dp[i][j];
    }
    int countSubstrings(string s, string t) {
        global_s = s;
        global_t = t;
        used = vector<vector<int>>(s.size(), vector<int>(t.size()));
        dp = vector<vector<int>>(s.size(), vector<int>(t.size()));
        int answer = 0;
        for(int i = 0; i < s.size(); i++){
            for(int j = 0; j < t.size(); j++){
                answer += rec(i, j);
            }
        }
        return answer;
    }
};