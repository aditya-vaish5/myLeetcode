/*
 * @lc app=leetcode id=263 lang=cpp
 *
 * [263] Ugly Number
 */

// @lc code=start
class Solution {
public:
    bool isUgly(int num) {
        if(num <= 0) return false;
        while(num > 0  && num%2 == 0) num/=2;
        cout << num << endl;
        while(num > 0  && num%3 == 0) num/=3;
        cout << num << endl;
        while(num > 0  && num%5 == 0) num/=5;
        cout << num << endl;
        if(num == 1) return true;
        return false;
    }
};
// @lc code=end

