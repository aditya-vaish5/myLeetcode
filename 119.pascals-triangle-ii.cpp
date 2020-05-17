/*
 * @lc app=leetcode id=119 lang=cpp
 *
 * [119] Pascal's Triangle II
 */

// @lc code=start
class Solution
{
public:
    vector<int> getRow(int rowIndex)
    {
        vector<int> curr;
        curr.push_back(1);
        if (rowIndex == 0)
        {
            return curr;
        }
        for (int i = 1; i <= rowIndex; i++)
        {
            curr.push_back(0);
            for (int j = i-1; j >=0; j--)
            {
                curr[j + 1] += curr[j];
            }
        }
            for(int p :curr)
                cout << p << ' ';
        return curr;
        
    }
};
// @lc code=end
