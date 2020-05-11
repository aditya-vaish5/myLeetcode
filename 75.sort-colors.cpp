/*
 * @lc app=leetcode id=75 lang=cpp
 *
 * [75] Sort Colors
 */

// @lc code=start
class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        int n = nums.size();
        int index = 0, start = 0, end = n - 1;
        while (index <= end && start < end)
        {
            if (nums[index] == 0)
            {
                nums[index] = nums[start];
                nums[start] = 0;
                index++;
                start++;
            }
            else if (nums[index] == 2)
            {
                nums[index] = nums[end];
                nums[end] = 2;
                end--;
            }
            else if (nums[index] == 1)
            {
                index++;
            }
            // for (int i : nums)
            // {
            //     cout << i << ' ';
            // }
            // cout << endl;
        }
        return;
    }
};
// @lc code=end
