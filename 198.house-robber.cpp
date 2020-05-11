/*
 * @lc app=leetcode id=198 lang=cpp
 *
 * [198] House Robber
 */

// @lc code=start
class Solution {
public:
    int n;
    int dp[10001];
    int f(const vector<int> &nums,int i){
        if(dp[i]!=-1)return dp[i];
        if(i > n-1){
            dp[i] = 0;
            return 0;
        }
        dp[i] = max(f(nums , i+1), nums[i] + f(nums,i+2));
        return dp[i];
    }
    int rob(vector<int>& nums) {
        int e=0 , o=0;
        memset(dp,-1,sizeof(dp));
        n = nums.size();
        return f(nums,0);
    }
};
// @lc code=end

