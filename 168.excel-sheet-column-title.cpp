/*
 * @lc app=leetcode id=168 lang=cpp
 *
 * [168] Excel Sheet Column Title
 */

// @lc code=start
class Solution {
public:
    string convertToTitle(int n) {
        string ans;
        
        while(n>0){
            n--;
            int rem = n % 26;
            char c = 'A' + rem  ;
            ans = c+ans;
            n/=26;
        }
        return ans;
    }
};
// @lc code=end

