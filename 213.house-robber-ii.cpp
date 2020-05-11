/*
 * @lc app=leetcode id=213 lang=cpp
 *
 * [213] House Robber II
 */

// @lc code=start
class Solution
{
public:
    int n;
    int dp[2][100000];
    int f(vector<int> &nums, int index, bool hasZero)
    {
        if(dp[hasZero?1:0][index] != -1){
            return dp[hasZero?1:0][index];
        }
        int ans = 0;
        if (index >= n)
        {
            return 0;
        }
        if (!(hasZero && index + 2 == n - 1))
        {
            ans = max(nums[index] + f(nums, index + 2, hasZero), ans);
        }
        if (!(hasZero && index + 3 == n - 1))
        {
            ans = max(nums[index] + f(nums, index + 3, hasZero), ans);
        }
        dp[hasZero ?1:0][index] =ans;
        return ans;
    }
    int rob(vector<int> &nums)
    {
        memset(dp,-1,sizeof(dp));
        n = nums.size();
        return max(f(nums, 0, true),max( f(nums, 1, false), f(nums,2,false)));
    }
};
// @lc code=end
