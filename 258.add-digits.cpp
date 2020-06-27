/*
 * @lc app=leetcode id=258 lang=cpp
 *
 * [258] Add Digits
 */

// @lc code=start
class Solution {
public:
    int addDigits(int num) {
        int t = num ;
        int sum =0;
        while(t!=0){
            sum +=t%10;
            t/=10;
        }
        if(sum < 10) return sum;
        return addDigits(sum);
    }
};
// @lc code=end

