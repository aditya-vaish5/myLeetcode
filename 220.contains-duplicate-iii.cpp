/*
 * @lc app=leetcode id=220 lang=cpp
 *
 * [220] Contains Duplicate III
 */

// @lc code=start
class Solution
{
public:
    bool containsNearbyAlmostDuplicate(vector<int> &nums, int k, int t)
    {
        map<long, long> m;
        for (int i = 0; i < nums.size(); ++i)
        {
            long x = nums[i];
            x-=t;
            auto it = m.lower_bound(x);

            while (it != m.end() && it->second < i-k)
                it = m.erase(it);

            if (it != m.end() && nums[i] >= it->first - t)
                return true;
            m[nums[i]] = i;
        }
        return false;
    }
};
// @lc code=end
