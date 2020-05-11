/*
 * @lc app=leetcode id=57 lang=cpp
 *
 * [57] Insert Interval
 *
 * https://leetcode.com/problems/insert-interval/description/
 *
 * algorithms
 * Hard (32.86%)
 * Likes:    1398
 * Dislikes: 158
 * Total Accepted:    231.4K
 * Total Submissions: 704.1K
 * Testcase Example:  '[[1,3],[6,9]]\n[2,5]'
 *
 * Given a set of non-overlapping intervals, insert a new interval into the
 * intervals (merge if necessary).
 * 
 * You may assume that the intervals were initially sorted according to their
 * start times.
 * 
 * Example 1:
 * 
 * 
 * Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
 * Output: [[1,5],[6,9]]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
 * Output: [[1,2],[3,10],[12,16]]
 * Explanation: Because the new interval [4,8] overlaps with
 * [3,5],[6,7],[8,10].
 * 
 * NOTE: input types have been changed on April 15, 2019. Please reset to
 * default code definition to get new method signature.
 * 
 */

// @lc code=start
// #include <bits/stdc++.h>
class Solution
{
public:
    vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
    {
        vector<vector<int>> ans;
        int n = intervals.size();
        if (n == 0)
        {
            ans.push_back(newInterval);
            return ans;
        }
        int prev_max = intervals[0][0];
        if(intervals[0][0]>newInterval[0]){
            prev_max = newInterval[0];
        }
        ans.push_back({prev_max, prev_max});
        int size = 0;
        bool isDone = false;
        for (auto x : intervals)
        {
            if (!isDone && newInterval[0] <= x[0])
            {
                if(newInterval[0]<=prev_max){
                    prev_max = max(newInterval[1], ans[size][1]);
                    ans[size][1] = prev_max;
                }else{
                    size++;
                    ans.push_back(newInterval);
                    prev_max = newInterval[1];
                }
                isDone = true;
            }
            if (x[0] <= prev_max)
            {
                prev_max = max(x[1], ans[size][1]);
                ans[size][1] = prev_max;
            }
            else
            {
                // cout << x[0] << ' ' << x[1] << ' '<<prev_max << endl;
                size++;
                ans.push_back(x);
                prev_max = x[1];
            }
        }
        if(!isDone){
                if(newInterval[0]<=prev_max){
                    prev_max = max(newInterval[1], ans[size][1]);
                    ans[size][1] = prev_max;
                }else{
                    size++;
                    ans.push_back(newInterval);
                    prev_max = newInterval[1];
                }
        }
        return ans;
    }
};
// @lc code=end
