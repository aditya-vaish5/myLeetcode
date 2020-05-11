/*
 * @lc app=leetcode id=78 lang=cpp
 *
 * [78] Subsets
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> ans;
    vector<int> t;
    void f(const vector<int> &nums,int n, int k, int curr, int len)
    {
        if (len == k)
        {
            ans.push_back(t);
        }
        for (int i = curr; i <n; i++)
        {
            t.push_back(nums[i]);
            f(nums,n, k, i + 1, len + 1);
            t.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int> nums)
    {
        for (int i = 0; i <= nums.size(); i++)
        {
            f(nums,nums.size(), i, 0, 0);
        }
        return ans;
    }
};
// @lc code=end
