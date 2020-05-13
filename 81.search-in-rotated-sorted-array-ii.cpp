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

            if (nums[l] < nums[mid])
            {
                if (target < nums[mid] && nums[l] <= target)
                    r = mid - 1;
                else
                    l = mid + 1;
            }
            else if (nums[mid] < nums[r])
            {
                if (target > nums[mid] && nums[r] >= target)
                    l = mid + 1;
                else
                    r = mid - 1;
            }
            else
            {
                if(nums[mid] == nums[l]) l++;
                if(nums[mid] == nums[r]) r--;
            }
        }
        return false;
    }
};
// @lc code=end
