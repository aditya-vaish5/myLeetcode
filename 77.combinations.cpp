/*
 * @lc app=leetcode id=77 lang=cpp
 *
 * [77] Combinations
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> ans;
    vector<int> t;
    void f(int n, int k, int curr,int len)
    {
        if (len == k)
        {
            ans.push_back(t);
        }
        for (int i = curr; i <= n; i++)
        {
            t.push_back(i);
            f(n, k, i + 1,len+1);
            t.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k)
    {
        f(n, k, 1,0);
        return ans;
    }
};
// @lc code=end
