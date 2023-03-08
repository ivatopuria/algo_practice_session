class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n = nums.size();
        int answer = 0;
        while(true){
            sort(nums.begin(), nums.end());
            int x = 0;
            for(int i = 0 ; i < n ; i++){
                if(nums[i] != 0){
                    x = nums[i];
                    break;
                }
            }
            if(x == 0){
                break;
            }
            answer += 1;
            for(int i = 0 ; i < n ; i++)
            {
                if(nums[i] > 0){
                    nums[i] -= x;
                }
            }
        }
        return answer;
    }
};