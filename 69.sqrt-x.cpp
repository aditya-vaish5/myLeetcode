/*
 * @lc app=leetcode id=69 lang=cpp
 *
 * [69] Sqrt(x)
 */

// @lc code=start
class Solution {
public:
    int mySqrt(int k) {
        long x =k;
        if(x < 2){
            return x;
        }
        long curr = 1;
        for(int i = 2;i<100000;i++){
            if(x < curr * curr)  return curr-1;
            if(x == curr*curr) return curr;
            curr++;
        }
        return -1;
    }
};
// @lc code=end

