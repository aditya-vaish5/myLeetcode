/*
 * @lc app=leetcode id=81 lang=cpp
 *
 * [81] Search in Rotated Sorted Array II
 */

// @lc code=start
class Solution
{
public:
    bool search(vector<int> &nums, int target)
    {
        int n = nums.size();
        int l = 0, r = n - 1, mid = (l + r) / 2;
        while (l <= r)
        {
            mid = (l + r) / 2;
            if (nums[mid] == target)
            {
                return true;
            }

            if (nums[mid] == nums[l] && nums[mid] == nums[r])
            {
                r--;
                l++;
            }
            else if (nums[l] <= target && target < nums[mid])
            {
                if (nums[mid] < target)
                    r = mid - 1;
                else
                    l = mid + 1;
            }
            else
            {
                if (nums[mid] < target && nums[r] >= target)
                    l = mid + 1;
                else
                    r = mid - 1;
            }
        }
        return false;
    }
};
// @lc code=end
