class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // nums[i], nums[j] and nums[k]
        //  * nums[i] + nums[j] + nums[k] == 0
        // such that i != j and j != k and i != k
        // * i < j < k
        // sort(nums)
        // O(n ^ 3)
        // [-1 -1 0  1]
        //   i    j  k
        int n=nums.size();
        
        sort(nums.begin(),nums.end());
        
        map<int,int> mp;
        for(int i = 0 ; i < n ; i++){
            mp[nums[i]] = i;
        }

        vector<vector<int>> answer;
        for(int i = 0 ; i < n ; i++){
            if(i > 0 and nums[i - 1] == nums[i]){
                continue;
            }
            for(int j = i + 1 ; j < n ; j++){
                if(j >= i + 2 and nums[j - 1] == nums[j]){
                    continue;
                }
                // nums[i] + nums[j] + nums[k] = 0
                // nums[k] = - nums[i] - nums[j]
                // k >= j + 1
                int numsk = - nums[i] - nums[j];
                if(mp.find(numsk) != mp.end() and mp[numsk] >= j + 1){
                    answer.push_back({nums[i],nums[j],numsk});
                }
                // for(int k = j + 1 ; k < n ; k++){
                //     if(k >= j + 2 and nums[k - 1] == nums[k]){
                //         continue;
                //     }
                //     if(nums[i] + nums[j] + nums[k] == 0){
                //         answer.push_back({nums[i],nums[j],nums[k]});
                //     }
                // }
            }
        }
        return answer;
    }
};