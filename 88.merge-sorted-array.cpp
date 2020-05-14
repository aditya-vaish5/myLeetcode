/*
 * @lc app=leetcode id=88 lang=cpp
 *
 * [88] Merge Sorted Array
 */

// @lc code=start
class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        //start from back
        int i = m - 1;
        int j = n - 1;
        int k = n + m - 1;
        while (i >= 0 && j >= 0)
        {
            if (nums1[i] > nums2[j])
            {
                nums1[k] = nums1[i];
                i--;
                k--;
            }
            else
            {
                nums1[k] = nums2[j];
                j--;
                k--;
            }
        }
        while (j >= 0)
        {
            nums1[k--] = nums2[j--];
        }
        while (i >= 0)
        {
            nums1[k--] = nums1[i--];
        }
    }
};
// @lc code=end
