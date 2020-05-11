/*
 * @lc app=leetcode id=56 lang=cpp
 *
 * [56] Merge Intervals
 *
 * https://leetcode.com/problems/merge-intervals/description/
 *
 * algorithms
 * Medium (38.35%)
 * Likes:    3595
 * Dislikes: 263
 * Total Accepted:    540.3K
 * Total Submissions: 1.4M
 * Testcase Example:  '[[1,3],[2,6],[8,10],[15,18]]'
 *
 * Given a collection of intervals, merge all overlapping intervals.
 * 
 * Example 1:
 * 
 * 
 * Input: [[1,3],[2,6],[8,10],[15,18]]
 * Output: [[1,6],[8,10],[15,18]]
 * Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into
 * [1,6].
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [[1,4],[4,5]]
 * Output: [[1,5]]
 * Explanation: Intervals [1,4] and [4,5] are considered overlapping.
 * 
 * NOTE: input types have been changed on April 15, 2019. Please reset to
 * default code definition to get new method signature.
 * 
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        vector<vector<int>> ans;
        if(intervals.size()==0){
            return ans;
        }
        int size = 0;
        
        sort(intervals.begin(), intervals.end());
        int prev_max = intervals[0][0];
        ans.push_back({prev_max,prev_max});
        for (auto x : intervals)
        {
            if(x[0]<=prev_max){
                prev_max=max(x[1],ans[size][1]);
                ans[size][1] = prev_max;
            }else{
                // cout << x[0] << ' ' << x[1] << ' '<<prev_max << endl;
                size++;
                ans.push_back(x);
                prev_max=x[1];
            }
        }
        return ans;
    }
};
// @lc code=end
