/*
 * @lc app=leetcode id=1423 lang=cpp
 *
 * [1423] Maximum Points You Can Obtain from Cards
 */

// @lc code=start
class Solution
{
public:
    int maxScore(vector<int> &cardPoints, int k)
    {
        vector<int> arr;
        int s = 0;
        int n = cardPoints.size();
        arr.push_back(0);
        for (int card : cardPoints)
        {
            s += card;
            arr.push_back(s);
        }
        int ans = 0;
        s = 0;
        for (int i = n - 1,j=1; i >= n - k; i--,j++)
        {
            s += cardPoints[i];
            ans = max(ans , s + arr[k-j]);
        }
        ans = max( ans , arr[k]);
        return ans;
    }
};
// @lc code=end
