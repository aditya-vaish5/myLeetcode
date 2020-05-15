/*
 * @lc app=leetcode id=90 lang=cpp
 *
 * [90] Subsets II
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        vector<int> t;
        ans.push_back(t);
        for (int i = 0; i < n; i++)
        {
            int count = 1;
            while (i + 1 < n && nums[i] == nums[i + 1])
            {
                count++;
                i++;
            }
            int curr = nums[i];
            int s = ans.size();
            for (int j = 0; j < s; j++)
            {
                vector<int> p = ans[j];
                for (int x = 0; x < count; x++)
                {
                    p.push_back(curr);
                    ans.push_back(p);
                }
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};
// @lc code=end
