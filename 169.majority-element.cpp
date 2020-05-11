/*
 * @lc app=leetcode id=169 lang=cpp
 *
 * [169] Majority Element
 */

// @lc code=start
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        for(unsigned int i =0 ;i<32;i++){
            int bit = 1 << i;
            int count =0;
            for(int j:nums)
                if(j & bit)
                    count++;
            if(count > n/2) ans |= bit;
        }
        return ans;
    }
};
// @lc code=end

