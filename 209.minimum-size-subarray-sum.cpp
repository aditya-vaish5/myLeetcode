/*
 * @lc app=leetcode id=209 lang=cpp
 *
 * [209] Minimum Size Subarray Sum
 */

// @lc code=start
class Solution
{
public:
    int minSubArrayLen(int s, vector<int> &nums)
    {
        int sum = 0, sum2 = 0;
        int ans = INT_MAX;
        int n = nums.size();
        if (nums.size() == 0)
            return 0;
        for (int i = 0, j = 0; i < n;)
        {
            while (i < n && sum - sum2 < s)
            {
                sum += nums[i];
                i++;
            }
            while (sum - sum2 >= s)
            {
                sum2 += nums[j];
                j++;
            }
            
            cout << i << ' ' << j << ' ' << ans << endl;
            ans = min(ans, i - j + 1);
        }
        if (sum < s)
        {
            return 0;
        }
        return ans;
    }
};
// @lc code=end
