/*
 * @lc app=leetcode id=321 lang=cpp
 *
 * [321] Create Maximum Number
 *
 * https://leetcode.com/problems/create-maximum-number/description/
 *
 * algorithms
 * Hard (26.54%)
 * Likes:    588
 * Dislikes: 205
 * Total Accepted:    36.8K
 * Total Submissions: 138.6K
 * Testcase Example:  '[3,4,6,5]\n[9,1,2,5,8,3]\n5'
 *
 * Given two arrays of length m and n with digits 0-9 representing two numbers.
 * Create the maximum number of length k <= m + n from digits of the two. The
 * relative order of the digits from the same array must be preserved. Return
 * an array of the k digits.
 * 
 * Note: You should try to optimize your time and space complexity.
 * 
 * Example 1:
 * 
 * 
 * Input:
 * nums1 = [3, 4, 6, 5]
 * nums2 = [9, 1, 2, 5, 8, 3]
 * k = 5
 * Output:
 * [9, 8, 6, 5, 3]
 * 
 * Example 2:
 * 
 * 
 * Input:
 * nums1 = [6, 7]
 * nums2 = [6, 0, 4]
 * k = 5
 * Output:
 * [6, 7, 6, 0, 4]
 * 
 * Example 3:
 * 
 * 
 * Input:
 * nums1 = [3, 9]
 * nums2 = [8, 9]
 * k = 3
 * Output:
 * [9, 8, 9]
 * 
 */

// @lc code=start
class Solution {
    void combine(std::vector<int> &res, std::vector<int> &v1, std::vector<int> &v2)
    {
        int len1 = v1.size();
        int len2 = v2.size();
        int len = res.size();
        int left = 0;
        int right = 0;
        for (int i = 0; i < len;) {
            if (right == len2 || left != len1 && v1[left] > v2[right]) {
                res[i++] = v1[left++];
            } else if (left == len1 || v2[right] > v1[left]) {
                res[i++] = v2[right++];
            } else {
                int ori_left = left;
                int ori_right = right;
                int tar = left;
                int last_greater = right;
                res[i++] = v1[left];
                while (1) {
                    ++left;
                    ++right;
                    if (left == len1 || right != len2 && v1[left] < v2[right]) {
                        left = ori_left;
                        break;
                    } else if (right == len2 || v1[left] > v2[right]) {
                        right = ori_right;
                        break;
                    }
                    if (v1[left] < v1[tar]) {
                        left = tar;
                        right = last_greater + 1;
                        break;
                    } else if (v1[left] > v1[tar]) {
                        last_greater = right;
                        tar = ori_left;
                    } else {
                        ++tar;
                    }
                    res[i++] = v1[left];
                }
            }
        }
    }
    void max_num(std::vector<int> &res, std::vector<int> &nums, int k)
    {
        res.clear();
        int len = nums.size();
        int diff = len - k;
        for (int i = 0; i < len; ++i) {
            while (res.size() > std::max(i - diff, 0) && nums[i] > res.back()) {
                res.pop_back();
            }
            if (res.size() < k) {
                res.push_back(nums[i]);
            }
        }
    }
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        std::vector<int> res(k);
        std::vector<int> cur(k);
        std::vector<int> temp1;
        std::vector<int> temp2;
        temp1.reserve(k);
        temp2.reserve(k);
        int len1 = nums1.size();
        int len2 = nums2.size();
        int max_len = std::min(len1, k);
        int min_len = std::max(k - len2, 0);
        for (int i = min_len; i <= max_len; ++i) {
            max_num(temp1, nums1, i);
            max_num(temp2, nums2, k - i);
            combine(cur, temp1, temp2);
            if (cur > res) {
                res.swap(cur);
            }
        }
        return res;
    }
};
// @lc code=end

