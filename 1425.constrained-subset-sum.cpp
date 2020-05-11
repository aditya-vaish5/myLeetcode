/*
 * @lc app=leetcode id=1425 lang=cpp
 *
 * [1425] Constrained Subset Sum
 */

// @lc code=start
class Solution
{
public:
    int n;
    const int M = -1;
    int dp[100001];
    int f(const vector<int> &nums, const int &k, int index)
    {
        if (index >= n)
        {
            return 0;
        }
        
        if (dp[index] != -1)
        {
            return dp[index];
        }
        int ans = 0;
        for (int i = index + 1; i < k + index + 1 && index < n; i++)
        {
            ans = max(ans, f(nums, k, i));
        }
        dp[index] = nums[index] + ans;
        // cout << index << ' ' << dp[index] << endl;
        return dp[index];
    }
    int constrainedSubsetSum(vector<int> &nums, int k)
    {
        n = nums.size();
        cout << n <<endl;
        memset(dp, M, sizeof(dp));


        int final = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            final = max(f(nums, k, i),final);
        };

        return final;
    }
};
// @lc code=end
