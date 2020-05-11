/*
 * @lc app=leetcode id=190 lang=cpp
 *
 * [190] Reverse Bits
 */

// @lc code=start
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ans =0;
        for(int i=0;i<32;i++){
            uint32_t k = 1 << i;
            uint32_t l = 1 << (31-i);
            if(k & n){
                ans |= l;
            }
        }
        return ans;
    }
};
// @lc code=end

