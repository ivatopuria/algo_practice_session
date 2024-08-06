class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        multiset<int> sw;
        vector<int> result;
        for (int i = 0; i < k; i++)
        {
            sw.insert(nums[i]);
        }
        result.push_back(*prev(sw.end()));
        int i=1, j=k;
        while (j<n) {
            sw.erase(sw.find(nums[i - 1]));
            sw.insert(nums[j]);
            result.push_back(*prev(sw.end()));
            j++;
            i++;
        }
        return result;
    }
};