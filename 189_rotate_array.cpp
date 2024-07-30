#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        k%=n;
        if(k==0) return;
        int start=0, end=n-k;

        for (int j = 0; j < n / k - 1; j++) {
            int secondPtr = start + k;
            for (int i = start; i < secondPtr; i++) {
                swap(nums[start], nums[end]);
                start++;
                end++;
            }
            end = n - k;
        }

        for(auto x : nums){
            cout << x << " ";
        }
        cout << "\n";

        // cout << end << "\n";

        if(n % k){
            end = n - 1;
            int take = k;
            int iter = 0;
            while(start < end){
                // if(iter++ == 4) break;
                // cout << start << " " << end << " ~ " << take << "\n";
                // for(auto x : nums){
                //     cout << x << " ";
                // }
                // cout << "\n";
                int len = end - start + 1;
                if(len == take){
                    break;
                }
                if(take > len - take){
                    for(int i = start; i < start + (len - take); i++){
                        swap(nums[i], nums[start + (len - take) + i - start]);
                    }
                    start = start + (len - take);
                    take = take - (len - take);
                }else{
                    for(int i = start; i < start + take; i++){
                        swap(nums[i], nums[start + (len - take) + i - start]);
                    }
                    start = start + take;
                }
            }
        }

    }
};

int main()
{
    Solution sl;
    vector<int> nums = {1, 2, 3,4,5,6};

    //  12, 13, 14       4,5,6, 7,8,9,10, 11,    1,2,3,
    //   12, 13, 14      1,2,3,         7,8,9,10, 11,  4,5,6,
    //    12, 13, 14      1,2,3,         4,5,6,   10, 11, 7,8,9,       
    //   12, 13, 14      1,2,3,         4,5,6,     7,8,    10, 11,9  

    sl.rotate(nums, 4);
    for (auto x : nums) {
        cout << x << " ";
    }
}