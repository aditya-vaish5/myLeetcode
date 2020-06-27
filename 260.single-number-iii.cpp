/*
 * @lc app=leetcode id=260 lang=cpp
 *
 * [260] Single Number III
 */

// @lc code=start
class Solution
{
public:
    vector<int> singleNumber(vector<int> &nums)
    {
        int diff = 0;
        for (int i : nums)
        {
            diff ^= i;
        }
        vector<int> res = {0, 0};
        diff &= -diff;
        for (int i : nums)
        {
            if (diff & i)
            {
                res[0] ^= i;
            }
            else
            {
                res[1] ^= i;
            }
        }
        return res;
    }
};
// @lc code=end
