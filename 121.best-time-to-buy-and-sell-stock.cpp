/*
 * @lc app=leetcode id=121 lang=cpp
 *
 * [121] Best Time to Buy and Sell Stock
 */

// @lc code=start
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int profit = 0;
    
        int curr_min = INT_MAX;
        // curr_max = INT_MIN;
        for (int i : prices)
        {
            if (i < curr_min)
            {
                curr_min = i;
            }
            else
            {
                // curr_max = mix(curr_max,i);
                profit = max(profit, i - curr_min);
            }
        }
        return profit;
    }
};
// @lc code=end
