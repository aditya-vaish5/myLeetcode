/*
 * @lc app=leetcode id=264 lang=cpp
 *
 * [264] Ugly Number II
 */

// @lc code=start
class Solution
{
public:
    int nthUglyNumber(int n)
    {
        int ugly[n];
        ugly[0] = 1;
        int rem2 = 0;
        int rem3 = 0;
        int rem5 = 0;
        for (int i = 1; i < n; i++)
        {
            int low = min(ugly[rem2] * 2, min(ugly[rem3] * 3, ugly[rem5] * 5));
            if (low == ugly[rem2] * 2)
            {
                rem2++;
            }
            if (low == ugly[rem3] * 3)
            {
                rem3++;
            }
            if (low == ugly[rem5] * 5)
            {
                rem5++;
            }
            ugly[i] = low;
        }
        return ugly[n-1];
    }
};
// @lc code=end
