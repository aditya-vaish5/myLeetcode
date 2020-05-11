/*
 * @lc app=leetcode id=70 lang=cpp
 *
 * [70] Climbing Stairs
 */

// @lc code=start
class Solution {
public:
    int dp[500000];
    int f(int x){
        if(dp[x] != -1) return dp[x];
        if(x<2) return 1;
        dp[x] =f(x-1) + f(x-2);
        return dp[x];
    }
    int climbStairs(int n) {
        memset(dp,-1,sizeof(dp));
        return f(n);
    }
};
// @lc code=end