class Solution {
public:
    const int inf = 1e9;
    vector < vector<int> > answer;
    void recursion(vector <int> permutation, int i, vector<int>& nums){
        if(i == nums.size()){
            answer.push_back(permutation);
            return;
        }
        int n = permutation.size();
        for(int j = 0; j < n; j++){
            if(permutation[j] == -inf){
                permutation[j] = nums[i];
                recursion(permutation, i + 1, nums);
                permutation[j] = -inf;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> permutation((int)nums.size(), -inf);
        recursion(permutation, 0, nums);
        return answer;
        // [1, 2, 3]

        // [* * *]
        //  ->
        // [1 * *],              [* 1 *], [* * 1]
        // -> [1 2 *], [1 * 2]
    }
};