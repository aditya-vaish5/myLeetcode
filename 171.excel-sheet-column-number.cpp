/*
 * @lc app=leetcode id=171 lang=cpp
 *
 * [171] Excel Sheet Column Number
 */

// @lc code=start
class Solution {
public:
    int titleToNumber(string s) {
        int len = s.length();
        int ans =0 ;
        for(char c: s){
            ans *= 26;
            ans += c - 'A';
            ans ++;
        }
        return ans;
    }
};
// @lc code=end

