/*
 * @lc app=leetcode id=89 lang=cpp
 *
 * [89] Gray Code
 */

// @lc code=start
class Solution
{
public:
    vector<int> grayCode(int n)
    {
        vector<int> ans;
        ans.push_back(0);
        for (int i = 0; i <= n-1; i++)
        {
            int len = ans.size();
            int x = 1 << i;
            for (int j = len - 1; j >= 0; j--)
            {
                ans.push_back(x + ans[j]);
            }
        }
        for(int i :ans) cout << i <<endl;
        return ans;
    }
};
// @lc code=end
