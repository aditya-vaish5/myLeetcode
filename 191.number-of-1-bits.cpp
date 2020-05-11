/*
 * @lc app=leetcode id=191 lang=cpp
 *
 * [191] Number of 1 Bits
 */

// @lc code=start
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count  =0;
        for(int i=0;i<32;i++){
            uint32_t t = 1 << i;
            if(t & n) count++;
        }
        return count;
    }
};
// @lc code=end

