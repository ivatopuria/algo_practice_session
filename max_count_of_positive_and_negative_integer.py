class Solution:
    def maximumCount(self, nums: List[int]) -> int:
        n = len(nums)

        index_0 = -1
        # find index of biggest negative number
        l, r = 0, n - 1
        while l <= r:
            m = (l + r) // 2
            if nums[m] < 0:
                index_0 = m
                l = m + 1
            else:
                r = m - 1
            
        index_1 = n
        # find index of smallest positive number
        l, r = 0, n - 1
        while l <= r:
            m = (l + r) // 2
            if nums[m] > 0:
                index_1 = m
                r = m - 1
            else:
                l = m + 1
        
        return max(n - index_1, index_0 + 1)